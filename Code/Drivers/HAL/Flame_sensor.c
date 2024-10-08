/*
 * Flame_sensor.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mohamed
 */

#include "Flame_sensor.h"
#include "gpio.h"
#include <avr/io.h>

void FlameSensor_init(void){
	// Set the direction of the flame sensor pin as input (since we need to read from it)
	GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID, PIN_INPUT);
}

uint8 FlameSensor_getValue(void){
	// Read and return the value of the flame sensor pin
	return GPIO_readPin(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID);
}
