#include "lab.h"

void stage_1(void){
        Pin_1_Write(1);
        Pin_2_Write(1);
        Pin_3_Write(0);
        Pin_4_Write(0);    
}

void stage_2(void){
        Pin_1_Write(0);
        Pin_2_Write(1);
        Pin_3_Write(0);
        Pin_4_Write(0);    
}

void stage_3(void){
        Pin_1_Write(0);
        Pin_2_Write(1);
        Pin_3_Write(1);
        Pin_4_Write(0);    
}

void stage_4(void){
        Pin_1_Write(0);
        Pin_2_Write(0);
        Pin_3_Write(1);
        Pin_4_Write(0);    
}

void stage_5(void){
        Pin_1_Write(0);
        Pin_2_Write(0);
        Pin_3_Write(1);
        Pin_4_Write(1);    
}

void stage_6(void){
        Pin_1_Write(0);
        Pin_2_Write(0);
        Pin_3_Write(0);
        Pin_4_Write(1);    
}

void stage_7(void){
        Pin_1_Write(1);
        Pin_2_Write(0);
        Pin_3_Write(0);
        Pin_4_Write(1);    
}

void stage_8(void){
        Pin_1_Write(1);
        Pin_2_Write(0);
        Pin_3_Write(0);
        Pin_4_Write(0);    
}

void (*stage_list[])(void) = {stage_1,stage_2,stage_3,stage_4,
    stage_5,stage_6,stage_7,stage_8};