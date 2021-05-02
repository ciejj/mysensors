/**
 * @file Automation.hpp
 * @author Grzegorz Krajewski
 *
 * Automation for buttons & sensors.
 *
 * @license GPL V2
 */

#pragma once

#include "../Mapping/Mapping.hpp"

void setOutput(const uint8_t& sensorId, const uint8_t& cmd = Relay::FLIP) {
  // test whether sensor with given ID exists and get it's index in container
  // TODO: Add debug message when idx is wrong & in any other places where: Sensors[idx]
  uint8_t idx = getIdx(sensorId);
  auto sensor = Sensors[idx];

  // check whether flip state of sensor
  const uint8_t state = (cmd == Relay::FLIP) ? !loadState(sensor.id) : cmd;
  saveState(sensor.id, state);

  // inverse state if sensors is Active Low
  bool bState = static_cast<bool>(state);
  bState = (ActiveLow == sensor.activelow) ? !bState : bState;

  digitalWrite(sensor.pin, bState);
  send(msgs[idx].set(state));
}

void clickCallback(void* pSensorId) {
  // TODO: Test whether this can be null or nullptr or unexpected value
  const uint8_t sensorId = static_cast<uint8_t>(reinterpret_cast<intptr_t>(pSensorId));
  setOutput(sensorId);
}


void setupButtons() {

boiler_room_bathtub.attachClick(clickCallback, BOILER_ROOM_BATHTTUB_ID );
garage_ceiling.attachClick(clickCallback, GARAGE_CEILING_ID);
boiler_room.attachClick(clickCallback, BOILER_ROOM_ID);
garage_corridor.attachClick(clickCallback, GARAGE_CORRIDOR_ID);
bar.attachClick(clickCallback, BAR_ID);
pantry_small.attachClick(clickCallback, PANTRY_SMALL_ID);
living_room_table.attachClick(clickCallback, LIVING_ROOM_TABLE_ID);
pantry_big.attachClick(clickCallback, PANTRY_BIG_ID);

garage_walls.attachClick(clickCallback, GARAGE_WALLS_ID);
stairs_scones.attachClick(clickCallback,STAIRS_SCONES_ID);
bedroom.attachClick(clickCallback, BEDROOM_ID);
bedroom_bed.attachClick(clickCallback, BEDROOM_BED_ID);
hall_up_b1.attachClick(clickCallback, HALL_UP_1_ID);
hall_up_b2.attachClick(clickCallback, HALL_UP_2_ID);
dressing_table.attachClick(clickCallback, DRESSING_TABLE_ID)

garage_outside_b1.attachClick(clickCallback, GARAGE_OUTSIDE_1_ID);
garage_outside_b2.attachClick(clickCallback, GARAGE_OUTSIDE_2_ID);
lights_outside_b1.attachClick(clickCallback, LIGHTS_OUTSIDE_1_ID);
lights_outside_b2.attachClick(clickCallback, LIGHTS_OUTSIDE_2_ID);
house_outside.attachClick(clickCallback, HOUSE_OUTSIDE_ID);
attic.attachClick(clickCallback, ATTIC_ID);

}
