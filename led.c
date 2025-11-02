/*
 * led.c
 *
 *  Created on: May 16, 2025
 *      Author: MOHAMED ELGENDY
 */

#include "led.h"
#include "gpio.h"


void LEDS_init(void){

	GPIO_setupPinDirection(RED_LED_PORT_ID, RED_LED_PIN_ID, PIN_OUTPUT);
	if(RED_LED_LOGIC==POSITIVE_LOGIC){
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
	}
	else{
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
	}

	GPIO_setupPinDirection(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, PIN_OUTPUT);
	if(GREEN_LED_LOGIC==POSITIVE_LOGIC){
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
	}
	else{
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
	}

	GPIO_setupPinDirection(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, PIN_OUTPUT);
	if(BLUE_LED_LOGIC==POSITIVE_LOGIC){
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
	}
	else{
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
	}

}

/*
 * Description :
 * function responsible for turning on a specified led
 */
void LED_on(LED_ID id){
	switch(id){
	case RED_LED:
		if(RED_LED_LOGIC==POSITIVE_LOGIC){
			GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
		}
		else{
			GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
		}
		break;

	case GREEN_LED:
		if(GREEN_LED_LOGIC==POSITIVE_LOGIC){
			GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
		}
		else{
			GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
		}
		break;

	case BLUE_LED:
		if(BLUE_LED_LOGIC==POSITIVE_LOGIC){
			GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
		}
		else{
			GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
		}
		break;
	}
}

/*
 * Description :
 * function responsible for turning off a specified led
 */
void LED_off(LED_ID id){
	switch(id){
	case RED_LED:
		if(RED_LED_LOGIC==POSITIVE_LOGIC){
			GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
		}
		else{
			GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
		}
		break;

	case GREEN_LED:
		if(GREEN_LED_LOGIC==POSITIVE_LOGIC){
			GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
		}
		else{
			GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
		}
		break;

	case BLUE_LED:
		if(BLUE_LED_LOGIC==POSITIVE_LOGIC){
			GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
		}
		else{
			GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
		}
		break;
	}
}


