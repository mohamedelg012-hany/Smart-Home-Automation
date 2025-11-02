#include "lcd.h"
#include "led.h"
#include "buzzer.h"
#include "motor.h"
#include "flame_sensor.h"
#include "lm35_sensor.h"
#include "ldr.h"
#include "adc.h"
#include <util/delay.h>

uint8 fanState0 = 0;
uint8 fanState1 = 0;
uint8 flame0 = 0;

void lightControl(uint16 intensity)
{
	if (intensity < 15)
	{
		LED_on(RED_LED);
		LED_on(GREEN_LED);
		LED_on(BLUE_LED);
	}
	else if (intensity >= 16 && intensity <= 50)
	{
		LED_on(RED_LED);
		LED_on(GREEN_LED);
		LED_off(BLUE_LED);
	}
	else if (intensity >= 51 && intensity <= 70)
	{
		LED_on(RED_LED);
		LED_off(GREEN_LED);
		LED_off(BLUE_LED);
	}
	else
	{
		LED_off(RED_LED);
		LED_off(GREEN_LED);
		LED_off(BLUE_LED);
	}
}

void speedFan(uint8 temp)
{
	if (temp >= 40)
	{
		DcMotor_Rotate(CLOCKWISE, 100);
		fanState1 = 1;
	}
	else if (temp >= 35)
	{
		DcMotor_Rotate(CLOCKWISE, 75);
		fanState1 = 1;
	}
	else if (temp >= 30)
	{
		DcMotor_Rotate(CLOCKWISE, 50);
		fanState1 = 1;
	}
	else if (temp >= 25)
	{
		DcMotor_Rotate(CLOCKWISE, 25);
		fanState1 = 1;
	}
	else
	{
		DcMotor_Rotate(STOP, 0);
		fanState1 = 0;
	}

	if (fanState1 != fanState0)
	{
		if (fanState1 == 1)
		{
			LCD_clearScreen();
			LCD_displayStringRowColumn(0, 0, "FAN is ON");
		}
		else
		{
			LCD_clearScreen();
			LCD_displayStringRowColumn(0, 0, "FAN is OFF");
		}
	}

	fanState0 = fanState1;
}

uint8 fireSensor(uint8 flame)
{
	if (flame != flame0)
	{
		if (flame)
		{
			Buzzer_on();
			LCD_clearScreen();
			LCD_displayStringRowColumn(0, 0, "CRITICAL ALERT!!");
		}
		else
		{
			Buzzer_off();
			LCD_clearScreen();
			fanState0 = !fanState1;
		}
		flame0 = flame;
		_delay_ms(50);
	}

	if (flame)
		return 1;
	else
		return 0;
}

int main(void)
{
	uint16 light_intensity = 0;
	uint8 temperature = 0;
	uint8 flame_detected = 0;

	LCD_init();
	LEDS_init();
	Buzzer_init();
	DCMotor_Init();
	FlameSensor_init();
	ADC_init();

	LCD_clearScreen();
	LCD_displayStringRowColumn(0, 0, "FAN is OFF");

	while (1)
	{
		light_intensity = LDR_getLightIntensity();
		temperature = LM35_getTemperature();
		flame_detected = FlameSensor_getValue();

		if (fireSensor(flame_detected))
		{
			continue;
		}

		lightControl(light_intensity);
		speedFan(temperature);

		LCD_displayStringRowColumn(1, 0, "Temp=");
		LCD_intgerToString(temperature);
		LCD_displayString("C LDR=");
		LCD_intgerToString(light_intensity);
		LCD_displayString("% ");
		_delay_ms(50);
	}
}
