/*
 * motor.h
 *
 *  Created on: May 17, 2025
 *      Author: MOHAMED ELGENDY
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "std_types.h"
#define MOTOR_EN1_PORT_ID              PORTB_ID
#define MOTOR_EN1_PIN_ID               PIN3_ID

#define MOTOR_IN1_PORT_ID              PORTB_ID
#define MOTOR_IN1_PIN_ID               PIN0_ID

#define MOTOR_IN2_PORT_ID              PORTB_ID
#define MOTOR_IN2_PIN_ID               PIN1_ID

typedef enum {
    STOP, CLOCKWISE, ANTICLOCKWISE
} DcMotor_State;

void DCMotor_Init(void);
void DCMotor_Rotate(DcMotor_State state, uint8 speed);



#endif /* MOTOR_H_ */

