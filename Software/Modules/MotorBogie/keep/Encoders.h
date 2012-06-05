/*
 * Encoders.h
 *
 * Created: 4/24/2012 4:18:42 PM
 *  Author: mfortner
 */ 

#include "BogieCommon.h"

#define ACTUATOR_QUADRATURE_LINECOUNT 2U

//drive encoder functions

uint16_t get_drive_speed();

//actuator encoder functions

void actuator_init();

uint16_t get_actuator_pos();
