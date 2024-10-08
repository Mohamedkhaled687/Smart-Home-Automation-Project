/*
 * main.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mohamed
 */

#include "adc.h"
#include "lcd.h"
#include "DC_MOTOR.h"
#include "Flame_sensor.h"
#include "lm35_sensor.h"
#include "BUZZER.h"
#include "LED.h"
#include "LDR.h"
#include "PWM.h"
#include <util/delay.h>

int main(void) {
    /* Initialize all peripherals */
    ADC_init();
    DC_Motor_init();
    LCD_init();
    LED_init();
    Buzzer_init();
    PWM_Timer0_init();
    FlameSensor_init();

    uint8 temperature_value = 0;
    uint16 intensity_value = 0;
    uint8 FAN_status = 0, previous_FAN_status = DC_MOTOR_STOP;
    uint8 flame_flag = 0;

    /* Static LCD Display - Set once */
    LCD_moveCursor(0, 4);
    LCD_displayString("FAN is OFF");
    LCD_moveCursor(1, 0);
    LCD_displayString("Temp=   ");
    LCD_moveCursor(1, 8);
    LCD_displayString("LDR=   %");

    uint8 previous_temperature_value = 0;
    uint8 previous_intensity_value = 0;

    while (1) {
        /* Get new temperature and light intensity values */
        temperature_value = LM35_getTemperature();
        intensity_value = LDR_getLightIntensity();

        /* Update temperature on LCD if it has changed */
        if (temperature_value != previous_temperature_value) {
            LCD_moveCursor(1, 5);
            LCD_intgerToString(temperature_value);
            if (temperature_value < 100) {
                LCD_displayCharacter(' ');  // Clear extra space if needed
            }
            previous_temperature_value = temperature_value;  // Update previous value
        }

        /* Update LDR intensity on LCD if it has changed */
        if (intensity_value != previous_intensity_value) {
            LCD_moveCursor(1, 12);
            LCD_intgerToString(intensity_value);
            if (intensity_value < 100) {
                LCD_displayCharacter(' ');  // Clear extra space if needed
            }
            previous_intensity_value = intensity_value;  // Update previous value
        }

        /* Control the LEDs based on intensity value */
        if (intensity_value <= 15) {
            // Turn on all LEDs
            LED_on(RED_ID);
            LED_on(GREEN_ID);
            LED_on(BLUE_ID);
        } else if (intensity_value >= 16 && intensity_value <= 50) {
            // Turn on RED and GREEN LEDs
            LED_off(BLUE_ID);
            LED_on(RED_ID);
            LED_on(GREEN_ID);
        } else if (intensity_value >= 51 && intensity_value <= 70) {
            // Turn on RED LED only
            LED_on(RED_ID);
            LED_off(GREEN_ID);
            LED_off(BLUE_ID);
        } else {
            // Turn off all LEDs
            LED_off(RED_ID);
            LED_off(GREEN_ID);
            LED_off(BLUE_ID);
        }

        /* Control the DC Motor based on temperature */
        if (temperature_value >= 40) {
            // Fan ON at 100% speed (full duty cycle)
            DC_Motor_Rotate(DC_MOTOR_CW, 100);
        } else if (temperature_value >= 35) {
            // Fan ON at 75% speed
            DC_Motor_Rotate(DC_MOTOR_CW, 75);  // 75% duty cycle
        } else if (temperature_value >= 30) {
            // Fan ON at 50% speed
            DC_Motor_Rotate(DC_MOTOR_CW, 50);  // 50% duty cycle
        } else if (temperature_value >= 25) {
            // Fan ON at 25% speed
            DC_Motor_Rotate(DC_MOTOR_CW, 25);   // 25% duty cycle
        } else {
            // Fan OFF
            DC_Motor_Rotate(DC_MOTOR_STOP, 0);
        }

        /* Get Current FAN Status */
        FAN_status = DC_Motor_getStatus();

        /* Only update FAN status if it has changed */
        if (FAN_status != previous_FAN_status) {
            LCD_moveCursor(0, 4);
            if (FAN_status != DC_MOTOR_STOP) {
                LCD_displayString("FAN is ON ");
            } else {
                LCD_displayString("FAN is OFF");
            }
            previous_FAN_status = FAN_status;  // Update previous FAN status
        }

        /* Flame Handle */
        if (FlameSensor_getValue() && !flame_flag) {
            LCD_clearScreen();            // Clear the screen for the alert message
            LCD_displayString("Critical Alert!!"); // Display critical alert message
            Buzzer_on();                  // Turn on the buzzer
            flame_flag = 1;               // Set the flag to indicate the flame has been detected
        } else if (!FlameSensor_getValue() && flame_flag) {
            flame_flag = 0;               // Reset the flag when the flame is no longer detected
            Buzzer_off();                 // Turn off the buzzer

            // Restore the original LCD display
            LCD_clearScreen();            // Clear the screen for the normal display
            LCD_moveCursor(0, 4);
            if (FAN_status != DC_MOTOR_STOP) {
                LCD_displayString("FAN is ON ");
            } else {
                LCD_displayString("FAN is OFF");
            }
            LCD_moveCursor(1, 0);
            LCD_displayString("Temp=   ");
            LCD_moveCursor(1, 5);
            LCD_intgerToString(temperature_value);
            LCD_moveCursor(1, 8);
            LCD_displayString("LDR=   %");
            LCD_moveCursor(1, 12);
            LCD_intgerToString(intensity_value);
        }

        _delay_ms(100);
    }
}
