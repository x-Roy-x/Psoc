#include "lab.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    protocol_init();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {   
        definition_direction();
        algorithm_work_rotor();       
    }
}