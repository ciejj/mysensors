/**
 * @file gateway.ino
 * @author Grzegorz Krajewski
 *
 * Implementation of the MySensors Gateway.
 *
 * @license GPL V2
 */

// Enable serial gateway
#define MY_GATEWAY_SERIAL

// Define a lower baud rate for Arduino's running on 8 MHz (Arduino Pro Mini 3.3V & SenseBender)
#if F_CPU == 16000000L
#define MY_BAUD_RATE 115200
#endif

enum doorbellEnum {OFF, ON, WaitingForRellese};
doorbellEnum doorbellState = OFF;

// Remember to add library to Arduino path
#include <MySensors.h>
#include "./Mapping/Mapping_board_02.hpp"
#include "./Automation/Automation_board_02.hpp"

// TODO: as this should be fixed, refactor to keep index fixed
// sensor[0] -> msgs[0]
// sensor[1] -> msgs[1]
// etc.
void setup() {
  for(uint8_t idx = 0; idx < maxSensors; idx++) {
    auto sensor = Sensors[idx];
    pinMode(sensor.pin, OUTPUT);
    msgs[idx] = MyMessage(sensor.id, V_STATUS);
    uint8_t currentState = loadState(sensor.id);

    // Check whether EEPROM cell was used before
    if (!(currentState == 0 || 1)) {
      currentState = Relay::OFF;
      saveState(sensor.id, currentState);
    }

    // inverse state if sensors is Active Low
    bool bState = static_cast<bool>(currentState);
    bState = (ActiveLow == sensor.activelow) ? !bState : bState;
    digitalWrite(sensor.pin, bState);
  }
  setupButtons();

}

void presentation() {
  // Send the sketch version information to the gateway and Controller
  sendSketchInfo("Gateway", "1.7");

  // Send actual states
  for (uint8_t idx = 0; idx < maxSensors; idx++) {
    auto sensor = Sensors[idx];
    present(sensor.id, S_BINARY, sensor.description);
    send(msgs[idx].set(loadState(sensor.id)));
  }

}

void loop() {

garage_ceiling.tick();
boiler_room.tick();
garage_corridor.tick();
bar.tick();
pantry_small.tick();
living_room_table.tick();
pantry_big.tick();

garage_walls.tick();
stairs_scones.tick();
bedroom.tick();
bedroom_bed_b1.tick();
hall_up_b1.tick();
hall_up_b2.tick();
dressing_table.tick();

garage_outside_b1.tick();
garage_outside_b2.tick();
lights_outside_b1.tick();
lights_outside_b2.tick();
house_outside.tick();
attic.tick();

}

void receive(const MyMessage &message) {
  // We only expect one type of message from controller. But we better check anyway.
  if (message.type==V_STATUS) {

    // check whether given sensor exists in Sensors cointainer
    const uint8_t idx = getIdx(message.sensor);
    const bool value = message.getBool();

    // Store state in eeprom and send message
    setOutput(Sensors[idx].id, value);
  }
}
