/**
 * @file Mapping.hpp
 * @author Grzegorz Krajewski
 *
 * Mappings.
 *
 * @license GPL V2
 */

#pragma once

#include <OneButton.h>

namespace Relay {
  const uint8_t OFF  = 0;
  const uint8_t ON   = 1;
  const uint8_t FLIP = 2;
}
const bool ActiveLow = true;

// Child ID declaration of relays
const uint8_t BATHROOM_DOWN_MIRROR_ID   = 11;
const uint8_t BATHROOM_DOWN_1_ID        = 12;
const uint8_t BATHROOM_DOWN_2_ID        = 13;
const uint8_t CLOAKROOM_DOWN_ID         = 14;
const uint8_t VESTIBULE_ID              = 15;
const uint8_t HALL_DOWN_STAIRS_ID       = 16;
const uint8_t HALL_DOWN_BATHROOM_ID     = 17;
const uint8_t HALL_DOWN_MIRROR_ID       = 18;
const uint8_t ROOM_DOWN_1_ID            = 19;
const uint8_t ROOM_DOWN_2_ID            = 20;
const uint8_t LIVING_ROOM_1_ID          = 21;
const uint8_t LIVING_ROOM_2_ID          = 22;
const uint8_t KITCHEN_1_ID              = 23;
const uint8_t KITCHEN_2_ID              = 24;
const uint8_t LIVING_ROOM_3_ID          = 25;
const uint8_t LIVING_ROOM_4_ID          = 26;
const uint8_t ROOM_B_1_ID               = 27;
const uint8_t ROOM_B_2_ID               = 28;
const uint8_t ROOM_L_1_ID               = 29;
const uint8_t ROOM_L_2_ID               = 30;
const uint8_t ROOM_L_3_ID               = 31;
const uint8_t ROOM_N_1_ID               = 32;
const uint8_t ROOM_N_2_ID               = 33;
const uint8_t CLOAKROOM_UP_ID           = 34;
const uint8_t LAUNDRY_ID                = 35;
const uint8_t BATHROOM_UP_1_ID          = 36;
const uint8_t BATHROOM_UP_2_ID          = 37;
const uint8_t BATHROOM_UP_MIRROR_ID     = 38;
const uint8_t OFFICE_1_ID               = 39;
const uint8_t HALL_OFFICE_ID            = 40;
const uint8_t HALL_UP_SCONES_ID         = 41;
const uint8_t OFFICE_2_ID               = 42;

typedef struct {
  const uint8_t id;
  const char* description;
  const uint8_t pin;
  bool activelow;
} SensorsStruct;

SensorsStruct Sensors [] = {
//  Child ID           description       pin activelow
{BATHROOM_DOWN_MIRROR_ID, "Łazienka dół lustro",  13, false},               
{BATHROOM_DOWN_1_ID,      "Łazienka dół S1",      12, false},          
{BATHROOM_DOWN_2_ID,      "Łazienka dół S2",      11, false},          
{CLOAKROOM_DOWN_ID,       "Garderoba dół",        10, false},         
{VESTIBULE_ID,            "Wiatorłap",             9, false},    
{HALL_DOWN_STAIRS_ID,     "Hol dół schody",        8, false},           
{HALL_DOWN_BATHROOM_ID,   "Hol dół łazienka",      7, false},             
{HALL_DOWN_MIRROR_ID,     "Kinkiety lustro",       6, false},           
{ROOM_DOWN_1_ID,          "Pokój dół S1",          5, false},    
{ROOM_DOWN_2_ID,          "Pokój dół S2",          4, false},    
{LIVING_ROOM_1_ID,        "Salon S1",              3, false},        
{LIVING_ROOM_2_ID,        "Salon S2",              2, false},        
{KITCHEN_1_ID,            "Kuchnia S1",           14, false},    
{KITCHEN_2_ID,            "Kuchnia S2",           15, false},    
{LIVING_ROOM_3_ID,        "Salon S3",             16, false},        
{LIVING_ROOM_4_ID,        "Salon S4",             17, false},            
{LAUNDRY_ID,              "Pralnia",              18, false},  
{BATHROOM_UP_1_ID,        "Łazienka góra S1",     19, false},        
{BATHROOM_UP_2_ID,        "Łazienka góra S2",     20, false},        
{BATHROOM_UP_MIRROR_ID,   "Łazienka góra lustro", 21, false},             
{OFFICE_1_ID,             "Biuro S1",             22, false},    
{HALL_OFFICE_ID,          "Hol góra S1",          23, false},    
{HALL_UP_SCONES_ID,       "Hol góra kinkiety",    24, false},         
{OFFICE_2_ID,             "Biuro",                25, false},
{ROOM_B_1_ID,             "Pokój B S1",           26, false},   
{ROOM_B_2_ID,             "Pokój B S2",           27, false},   
{ROOM_L_1_ID,             "Pokój L S1",           28, false},   
{ROOM_L_2_ID,             "Pokój L S2",           29, false},   
{ROOM_L_3_ID,             "Pokój L S3",           30, false},   
{ROOM_N_1_ID,             "Pokój N S1",           31, false},   
{ROOM_N_2_ID,             "Pokój N S2",           32, false},   
{CLOAKROOM_UP_ID,         "Garderoba góra",       33, false}
};
const uint8_t maxSensors = sizeof(Sensors) / sizeof(SensorsStruct);
MyMessage msgs[maxSensors+1]; //door is extra case

uint8_t getIdx(uint8_t sensorId) {
  for (uint8_t i = 0; i < maxSensors; i++) {
    if (Sensors[i].id == sensorId) return(i);
  }
  return(-1);
}

// Pushbuttons declaration
// Remember that names should be consistent with main loop in gateway.ino
OneButton bathroom_down_mirror(A0,true);
OneButton bathroom_down_b1(A1,true);
OneButton bathroom_down_b2(A2,true);
OneButton cloakroom_down(A3,true);
OneButton vestibule_b1(A4,true);
OneButton hall_down_stairs_b1(A5,true);
OneButton hall_down_bathroom_b1(A6,true);
OneButton hall_down_mirror_b1(A7,true);
OneButton room_down_b1(A8,true);
OneButton room_down_b2(A9,true);
OneButton living_room_b1(A10,true);
OneButton living_room_b2(A11,true);
OneButton kitchen_b1(A12,true);
OneButton kitchen_b2(A13,true);
OneButton living_room_b3(A14,true);
OneButton living_room_b4(A15,true);
OneButton laundry_b1(53,true);
OneButton bathroom_up_b1(52,true);
OneButton bathroom_up_b2(51,true);
OneButton bathroom_up_mirror(50,true);
OneButton office_b1(49,true);
OneButton hall_office_b1(48,true);
OneButton hall_up_scones_b1(47,true);
OneButton office_b2(46,true);
OneButton room_b_b1(45,true);
OneButton room_b_b2(44,true);
OneButton room_l_b1(43,true);
OneButton room_l_b2(42,true);
OneButton room_n_b1(41,true);
OneButton room_n_b2(40,true);
OneButton cloakroom_up(39,true);