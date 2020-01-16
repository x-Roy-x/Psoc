#include "lab.h"

volatile uint8 time = 0;
volatile uint8 direction = 0;
volatile uint8 speed = 0;

uint8 value_PWM = 0;

uint8 set_pwm(void);

extern void(*stage_list[])();

char stage_rotor[8]={0b0011,0b0010,0b0110,0b0100,0b1100,0b1000,0b1001,0b0001};

CY_ISR(Timer_Handler){
    time++;
    if(8 == time){
            time = 0;
    }
    Timer_ClearInterrupt(Timer_INTR_MASK_TC);
}

CY_ISR(SW_1_Handler){
    direction = !direction;
    SW_1_ClearInterrupt();
}

CY_ISR(SW_2_Handler){
    direction = 2;
    SW_2_ClearInterrupt();
}

CY_ISR(SW_3_Handler){
    speed -= 10;
    if(200 < speed){
        speed = 0;
    }
    SW_3_ClearInterrupt();
}

CY_ISR(SW_4_Handler){
    speed += 10;
    if(100 < speed && 150 > speed){
        speed = 100;
    }
    SW_4_ClearInterrupt();
}

void algorithm_init(void){
    Timer_Start();
    PWM_Start();
    Timer_Int_StartEx(Timer_Handler);
    SW_Int_1_StartEx(SW_1_Handler);
    SW_Int_2_StartEx(SW_2_Handler);
    SW_Int_3_StartEx(SW_3_Handler);
    SW_Int_4_StartEx(SW_4_Handler);
}

void enc_init(void){
    QuadDec_Start();
    QuadDec_WriteCounter(0);
}

uint8 set_pwm(void){
    uint8 value_encoder = 0;
    value_encoder = QuadDec_ReadCounter();
    if(10 < value_encoder && 20 > value_encoder){
        value_encoder = 10;
        QuadDec_WriteCounter(10);
    }
    if(2 > value_encoder){
        value_encoder = 2;
        QuadDec_WriteCounter(2); 
    }    
    return value_encoder * 10;
}

void active_stage(){
    if(0 != speed || 0 != direction){
        Timer_WritePeriod(2200 - (speed*10));
        
        if(1 == direction){
            Rotor_Write(stage_rotor[7-time]);
            //stage_list[time]();  
        }else if(2 == direction){
            Rotor_Write(stage_rotor[time]);
            //stage_list[time]();  
        }
    }
}

void algorithm_work_rotor(void){ 
    value_PWM = set_pwm();
    PWM_WriteCompare(value_PWM);
    active_stage();
}