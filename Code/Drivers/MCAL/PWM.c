/*
 * PWM.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mohamed
 */


#include "PWM.h"
#include "gpio.h"
#include <avr/io.h>

void PWM_Timer0_init(void){

    TCNT0 = 0; // Start Count From Zero

    // Make the OC0 as Output PIN -> pin which generates the PWM signal
    GPIO_setupPinDirection(PORTB_ID , PWM_OUTPUT_PIN , PIN_OUTPUT);

    /*
        1. Set Fast PWM Mode: WGM01 = 1 & WGM00
        2. Set non-inverting Mode (Clear OC0 pin on compare match) COM01 = 1
        3. Set prescaler 1024: CS00 = 1 & CS02 = 1
    */
    TCCR0 = (1 << WGM01) | (1 << WGM00) | (1 << COM01) | (1 << CS02) | (1 << CS00);
}

void PWM_Set_Duty_Cycle(uint8 duty_cycle){

	/* Set Duty Cycle */

	if(duty_cycle > 100)
		duty_cycle = 100;

	OCR0 = (uint8)(((uint16)255 * duty_cycle) / 100);
}
