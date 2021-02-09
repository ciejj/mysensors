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

void bathroomDownOff() {
  setOutput(BATHROOM_DOWN_MIRROR_ID, Relay::OFF);
  setOutput(BATHROOM_DOWN_1_ID, Relay::OFF);
  setOutput(BATHROOM_DOWN_2_ID, Relay::OFF);
}

void roomDownOff() {
  setOutput(BATHROOM_DOWN_1_ID, Relay::OFF);
  setOutput(BATHROOM_DOWN_2_ID, Relay::OFF);
}

void livingRoomOff() {
  setOutput(LIVING_ROOM_1_ID, Relay::OFF);
  setOutput(LIVING_ROOM_2_ID, Relay::OFF);
  setOutput(LIVING_ROOM_3_ID, Relay::OFF);
  setOutput(LIVING_ROOM_4_ID, Relay::OFF);
}

void livingRoomOn() {
  setOutput(LIVING_ROOM_1_ID, Relay::ON);
  setOutput(LIVING_ROOM_2_ID, Relay::ON);
  setOutput(LIVING_ROOM_3_ID, Relay::ON);
  setOutput(LIVING_ROOM_4_ID, Relay::ON);
}

void kitchenOff() {
  setOutput(KITCHEN_1_ID, Relay::OFF);
  setOutput(KITCHEN_2_ID, Relay::OFF);
}

void roomBOff() {
  setOutput(ROOM_B_1_ID, Relay::OFF);
  setOutput(ROOM_B_2_ID, Relay::OFF);
}

void roomLOff() {
  setOutput(ROOM_L_1_ID, Relay::OFF);
  setOutput(ROOM_L_2_ID, Relay::OFF);
}

void roomNOff() {
  setOutput(ROOM_N_1_ID, Relay::OFF);
  setOutput(ROOM_N_2_ID, Relay::OFF);
}

void bathroomUpOff() {
  setOutput(BATHROOM_UP_1_ID, Relay::OFF);
  setOutput(BATHROOM_UP_2_ID, Relay::OFF);
  setOutput(BATHROOM_UP_MIRROR_ID, Relay::OFF);
}

void officeOff() {
  setOutput(OFFICE_1_ID, Relay::OFF);
  setOutput(OFFICE_1_ID, Relay::OFF);
}

void setupButtons() {

bathroom_down_mirror.attachClick(clickCallback, BATHROOM_DOWN_MIRROR_ID);

bathroom_down_b1.attachClick(clickCallback, BATHROOM_DOWN_1_ID);
bathroom_down_b1.attachLongPressStart(bathroomDownOff);

bathroom_down_b2.attachClick(clickCallback, BATHROOM_DOWN_2_ID);
bathroom_down_b2.attachLongPressStart(bathroomDownOff);

cloakroom_down.attachClick(clickCallback, CLOAKROOM_DOWN_ID);

vestibule_b1.attachClick(clickCallback,VESTIBULE_ID);

hall_down_stairs_b1.attachClick(clickCallback, HALL_DOWN_STAIRS_ID);

hall_down_bathroom_b1.attachClick(clickCallback, HALL_DOWN_BATHROOM_ID);

hall_down_mirror_b1.attachClick(clickCallback,HALL_DOWN_MIRROR_ID);

room_down_b1.attachClick(clickCallback, ROOM_DOWN_1_ID);
room_down_b1.attachLongPressStart(roomDownOff);

room_down_b2.attachClick(clickCallback, ROOM_DOWN_2_ID);
room_down_b2.attachLongPressStart(roomDownOff);

living_room_b1.attachClick(clickCallback, LIVING_ROOM_1_ID);
living_room_b1.attachLongPressStart(livingRoomOff);
living_room_b1.attachDoubleClick(livingRoomOn);

living_room_b2.attachClick(clickCallback, LIVING_ROOM_2_ID);
living_room_b2.attachLongPressStart(livingRoomOff);
living_room_b2.attachDoubleClick(livingRoomOn);

kitchen_b1.attachClick(clickCallback, KITCHEN_1_ID);
kitchen_b1.attachLongPressStart(kitchenOff);

kitchen_b2.attachClick(clickCallback, KITCHEN_2_ID);
kitchen_b2.attachLongPressStart(kitchenOff);

living_room_b3.attachClick(clickCallback, LIVING_ROOM_3_ID);
living_room_b3.attachLongPressStart(livingRoomOff);
living_room_b3.attachDoubleClick(livingRoomOn);

living_room_b4.attachClick(clickCallback, LIVING_ROOM_4_ID);
living_room_b4.attachLongPressStart(livingRoomOff);
living_room_b4.attachDoubleClick(livingRoomOn);

room_b_b1.attachClick(clickCallback, ROOM_B_1_ID);
room_b_b1.attachLongPressStart(roomBOff);

room_b_b2.attachClick(clickCallback, ROOM_B_2_ID);
room_b_b2.attachLongPressStart(roomBOff);

room_l_b1.attachClick(clickCallback, ROOM_L_1_ID);
room_l_b1.attachLongPressStart(roomLOff);

room_l_b2.attachClick(clickCallback, ROOM_L_2_ID);
room_l_b2.attachLongPressStart(roomLOff);

room_n_b1.attachClick(clickCallback, ROOM_N_1_ID);
room_n_b1.attachLongPressStart(roomNOff);

room_n_b2.attachClick(clickCallback, ROOM_N_2_ID);
room_n_b2.attachLongPressStart(roomNOff);

cloakroom_up.attachClick(clickCallback,CLOAKROOM_UP_ID);

laundry_b1.attachClick(clickCallback,LAUNDRY_ID);

bathroom_up_b1.attachClick(clickCallback,BATHROOM_UP_1_ID);
bathroom_up_b1.attachLongPressStart(bathroomUpOff);

bathroom_up_b2.attachClick(clickCallback,BATHROOM_UP_2_ID);
bathroom_up_b2.attachLongPressStart(bathroomUpOff);

bathroom_up_mirror.attachClick(clickCallback, BATHROOM_UP_MIRROR_ID);

office_b1.attachClick(clickCallback,OFFICE_1_ID);
office_b1.attachLongPressStart(officeOff);

office_b2.attachClick(clickCallback, OFFICE_2_ID);
office_b2.attachLongPressStart(officeOff);

hall_office_b1.attachClick(clickCallback,HALL_OFFICE_ID);

hall_up_scones_b1.attachClick(clickCallback,HALL_UP_SCONES_ID);
}
