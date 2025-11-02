/*
 * ldr.c
 *
 *  Created on: May 17, 2025
 *      Author: mobilap
 */


#include "ldr.h"
#include "adc.h"


uint16 LDR_getLightIntensity(void) {
    uint16 adc_Value;
    uint16 lightIntensity;

    /* Read ADC value from LDR channel */
    adc_Value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

    /*
     * Convert ADC value to percentage (0-100%)
     * Since LDR resistance decreases with light, we invert the percentage:
     * - High ADC value (high voltage) = low light
     * - Low ADC value (low voltage) = high light
     */
    lightIntensity = (uint16)(((uint32)adc_Value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));



    return lightIntensity;
}
