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
const uint8_t BOILER_ROOM_BATHTTUB_ID    = 50;
const uint8_t GARAGE_CEILING_ID          = 51;
const uint8_t BOILER_ROOM_ID             = 52;
const uint8_t GARAGE_CORRIDOR_ID         = 53;
const uint8_t BAR_ID                     = 54;
const uint8_t PANTRY_SMALL_ID            = 55;
const uint8_t LIVING_ROOM_TABLE_ID       = 56;
const uint8_t PANTRY_BIG_ID              = 57;
const uint8_t STAIRS_SCONES_ID           = 58;
const uint8_t BEDROOM_S1_ID              = 59;
const uint8_t BEDROOM_S2_ID              = 60;
const uint8_t BEDROOM_BED_ID             = 61;
const uint8_t HALL_UP_1_ID               = 62;
const uint8_t HALL_UP_2_ID               = 63;
const uint8_t GARAGE_WALLS_ID            = 64;
const uint8_t GARAGE_OUTSIDE_1_ID        = 65;
const uint8_t GARAGE_OUTSIDE_2_ID        = 66;
const uint8_t LIGHTS_OUTSIDE_1_ID        = 67;
const uint8_t LIGHTS_OUTSIDE_2_ID        = 68;
const uint8_t HOUSE_OUTSIDE_ID           = 69;
const uint8_t ATTIC_ID                   = 70;

typedef struct {
  const uint8_t id;
  const char* description;
  const uint8_t pin;
  bool activelow;
} SensorsStruct;

SensorsStruct Sensors [] = {
//  Child ID           description       pin activelow
{BOILER_ROOM_BATHTTUB_ID, "kotłownia wanna",      13, false},               
{GARAGE_CEILING_ID,       "garaż sufit",          12, false},          
{BOILER_ROOM_ID,          "kotłownia sufit",      11, false},          
{GARAGE_CORRIDOR_ID,      "garaż korytaż",        10, false},         
{BAR_ID,                  "barek",                 9, false},    
{PANTRY_SMALL_ID,         "spiżarnia mała",        8, false},           
{LIVING_ROOM_TABLE_ID,    "salon stół",            7, false},             
{PANTRY_BIG_ID,           "spiżarnia duża",        6, false},           
{STAIRS_SCONES_ID,        "kinkiety schody",       5, false},    
{BEDROOM_S1_ID,           "sypialnia S1",          4, false},    
{BEDROOM_S2_ID,           "sypialania S2",         3, false},        
{BEDROOM_BED_ID,          "sypialnia łóżko",       2, false},        
{HALL_UP_1_ID,            "góra hol sufit S1",    14, false},    
{HALL_UP_2_ID,            "góra hol sufit S2",    15, false},    
{GARAGE_WALLS_ID,         "garaż ściany",         16, false},        
{GARAGE_OUTSIDE_1_ID,     "podbitka dół S1",      18, false},            
{GARAGE_OUTSIDE_2_ID,     "podbitka dół S2",      19, false},  
{LIGHTS_OUTSIDE_1_ID,     "zewnętrzne S1",        20, false},        
{LIGHTS_OUTSIDE_2_ID,     "zewnętrzne S2",        21, false},        
{HOUSE_OUTSIDE_ID,        "podbitka góra",        22, false},
{ATTIC_ID,                "strych",               23, false}     
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
OneButton boiler_room_bathtub(A0,true);
OneButton garage_ceiling(A1,true);
OneButton boiler_room(A2,true);
OneButton garage_corridor(A3,true);
OneButton bar(A4,true);
OneButton pantry_small(A5,true);
OneButton living_room_table(A6,true);
OneButton pantry_big(A7,true);
OneButton stairs_scones(A8,true);
OneButton bedroom_b1(A9,true);
OneButton bedroom_b2(A10,true);
OneButton bedroom_bed_b1(A11,true);
OneButton bedroom_bed_b2(A12,true);
OneButton hall_up_b1(A13,true);
OneButton hall_up_b2(A14,true);
OneButton garage_walls(A15,true);
OneButton garage_outside_b1(52,true);
OneButton garage_outside_b2(51,true);
OneButton lights_outside_b1(50,true);
OneButton lights_outside_b2(49,true);
OneButton house_outside(48,true);
OneButton attic(47,true);
