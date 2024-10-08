/*
 * LDR.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mohamed
 */

#ifndef LDR_H_
#define LDR_H_

#include "std_types.h"

// ADC channel where the LDR sensor is connected
#define LDR_SENSOR_CHANNEL_ID          0

// Maximum voltage output of the LDR sensor
#define LDR_SENSOR_MAX_VOLT_VALUE      2.56

// Maximum light intensity the sensor can measure (0 to 100%)
#define LDR_SENSOR_MAX_LIGHT_INTENSITY 100

// Function to read the light intensity
uint16 LDR_getLightIntensity(void);

#endif /* LDR_H_ */

