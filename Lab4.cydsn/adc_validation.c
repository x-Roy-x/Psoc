#include "lab.h"

int y = 0;
int x = 0;

void adc_validation_init(void){
    ADC_Start();
    ADC_StartConvert();
    PWM_X_Start();
    PWM_Y_Start();
}

void adc_get_led_position(void){
    x = ADC_GetResult16(0);
    y = ADC_GetResult16(1);   
    
    PWM_X_WriteCompare(x);
    PWM_Y_WriteCompare(y); 
}