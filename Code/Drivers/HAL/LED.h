/*
 * LED.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mohamed
 */

#ifndef LED_H_
#define LED_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define POSITIVE_LOGIC

#define LED_PORT_ID 	PORTB_ID


#define RED_ID 5
#define GREEN_ID 6
#define BLUE_ID 7

#define RED_LED_PIN_ID  PIN5_ID
#define GREEN_LED_PIN_ID  PIN6_ID
#define BLUE_LED_PIN_ID  PIN7_ID


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void LED_init();
void LED_on(uint8 LED_PIN_ID);
void LED_off(uint8 LED_PIN_ID);


#endif /* LED_H_ */
