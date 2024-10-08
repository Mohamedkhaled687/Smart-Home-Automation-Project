/*
 * DC_MOTOR.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mohamed
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define DC_MOTOR_PORT_ID 	PORTB_ID

#define IN1_PIN_ID 		PIN0_ID
#define IN2_PIN_ID 		PIN1_ID

/*******************************************************************************
 *                           Enum and Types                                    *
 *******************************************************************************/

/* Typedef for the Dc_Motor_State enum */
typedef enum {
	DC_MOTOR_STOP,        /* Stop motor */
	DC_MOTOR_CW,          /* Rotate clockwise */
	DC_MOTOR_CCW          /* Rotate counterclockwise (anti-clockwise) */
} Dc_Motor_State;

/*******************************************************************************
 *                           Function Prototypes                               *
 *******************************************************************************/

void DC_Motor_init(void);
void DC_Motor_Rotate(Dc_Motor_State state, uint8 speed);
Dc_Motor_State DC_Motor_getStatus(void);

#endif /* DC_MOTOR_H_ */
