/*
 * LDR.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mohamed
 */

#include "LDR.h"
#include "adc.h"

// Function to calculate the light intensity based on the ADC value
uint16 LDR_getLightIntensity(void) {
    // Read the ADC value from LDR_SENSOR_CHANNEL_ID
    uint16 adcValue = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

    // Convert ADC value to voltage (based on maximum ADC value and reference voltage)
    float voltage = ((float)adcValue / ADC_MAXIMUM_VALUE) * ADC_REF_VOLT_VALUE;

    // Calculate light intensity directly proportional to voltage
    float lightIntensity = (voltage / LDR_SENSOR_MAX_VOLT_VALUE) * LDR_SENSOR_MAX_LIGHT_INTENSITY;

    // Return the light intensity as an integer value
    return (uint16)lightIntensity;
}
