#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {   
        uint8 a,b,c,d,e,combination;
        a = !SW_1_Read();
        b = !SW_2_Read();
        c = !SW_3_Read();
        d = !SW_4_Read();
        e = !SW_5_Read();
        
        /*combination =(a && b && !c && !d && !e) || (a && !b && c && !d && !e) 
        || (a && !b && !c && d && !e) || (!a && b && c && !d && !e) || (!a && b && !c && d && !e) 
        || (!a && !b && c && d && !e) || (a && b && c && !d && !e);*/
        
        combination =(a && b && !c && !d && !e) || (a && c && !d && !e) 
        || (a && !b && !c && d && !e) || (b && c && !d && !e) || (!a && b && !c && d && !e) 
        || (!a && !b && c && d && !e);
        Pin_Blue_Write(combination);  
    }
}