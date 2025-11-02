/*
 * pwm.c
 *
 *  Created on: May 17, 2025
 *      Author: mobilap
 */


// PWM.c
#include "PWM.h"
#include "gpio.h"
#include "common_macros.h"
#include <avr/io.h>

void PWM_Timer0_Start(uint8 duty_cycle)
{
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);
    /* Configure Timer0 in Fast PWM mode */
	TCNT0=0;
    TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS02) | (1 << CS00);

    /* Set PWM duty cycle */
    OCR0 = (uint8)((duty_cycle * 255) / 100);

    /* Configure PB3/OC0 as output */

}
