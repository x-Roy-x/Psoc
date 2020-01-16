#include "project.h"

void algorithm_1(void);
void algorithm_2(void);

volatile int time = 0;
volatile int number_algorithm = 1;

CY_ISR(Timer_Handler){
    time++;
    Timer_ClearInterrupt(Timer_INTR_MASK_TC);
}

CY_ISR(SW_Handler){
    number_algorithm = !number_algorithm;
    SW_ClearInterrupt();
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    Timer_Start();
    Timer_Int_StartEx(Timer_Handler);
    SW_Int_StartEx(SW_Handler);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {   
        if(20 == time){
            time = 0;
        }else{
            if(1 == number_algorithm){
                algorithm_1();
            }else if(0 == number_algorithm){
                algorithm_2();
            }    
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

void algorithm_2(){
    Pin_Green_Write(0);
    Pin_Yellow_Write(0);
    Pin_Red_Write(0);
    if(6 == time || 8 == time){
        Pin_Yellow_Write(1);
        Pin_Green_Write(1);
    }else if(time < 8) {
        Pin_Green_Write(1);
    }else if(8 < time && time < 16) {
        Pin_Red_Write(1);
    }else if(16 == time || 18 == time) {
        Pin_Yellow_Write(1);
    }else{
        Pin_Green_Write(0);
        Pin_Yellow_Write(0);
        Pin_Red_Write(0);
    }
}