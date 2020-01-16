#include "lab.h"

extern uint8 time_red;
extern uint8 time_yellow;
extern uint8 time_green;

uint8 sum_time1;
uint8 sum_time2;

volatile uint8 time = 0;
volatile uint8 number_algorithm = 1;

void algorithm_1(void);
void algorithm_2(void);

CY_ISR(Timer_Handler){
    time++;
    Timer_ClearInterrupt(Timer_INTR_MASK_TC);
}

CY_ISR(SW_Handler){
    time = 0;
    number_algorithm = !number_algorithm;
    SW_ClearInterrupt();
}

void algorithm_init(void){
    Timer_Start();
    Timer_Int_StartEx(Timer_Handler);
    SW_Int_StartEx(SW_Handler);
}

void algorithm_definition(void){
    sum_time1=time_red + time_yellow;
    sum_time2 = sum_time1 + time_green;
    
    if(20 == time && 1 == number_algorithm){
        time = 0;
    }else if(sum_time2 == time && 0 == number_algorithm){
        time = 0;
    }else{
        if(1 == number_algorithm){
            algorithm_1();
        }else if(0 == number_algorithm){
            algorithm_2();
        }    
    } 
}

void algorithm_1(){
    Pin_Green_Write(0);
    Pin_Yellow_Write(0);
    Pin_Red_Write(0);
    if(6 == time || 8 == time){
        Pin_Yellow_Write(1);
        Pin_Red_Write(1);
    }else if(time < 8) {
        Pin_Red_Write(1);
    }else if(8 < time && time < 16) {
        Pin_Green_Write(1);
    }else if(16 == time || 18 == time) {
        Pin_Yellow_Write(1);
    }else{
        Pin_Green_Write(0);
        Pin_Yellow_Write(0);
        Pin_Red_Write(0);
    }
}

void algorithm_2(void){
    Pin_Green_Write(0);
    Pin_Yellow_Write(0);
    Pin_Red_Write(0);
    if(time < time_red){
        Pin_Red_Write(1);
    }else if(time_red <= time && time < sum_time1) {
        Pin_Yellow_Write(1);
    }else if(sum_time1 <= time && time < sum_time2) {
        Pin_Green_Write(1);
    }else{
        Pin_Green_Write(0);
        Pin_Yellow_Write(0);
        Pin_Red_Write(0);
    }
}