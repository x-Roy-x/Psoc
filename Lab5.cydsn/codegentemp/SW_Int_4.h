/*******************************************************************************
* File Name: SW_Int_4.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_SW_Int_4_H)
#define CY_ISR_SW_Int_4_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void SW_Int_4_Start(void);
void SW_Int_4_StartEx(cyisraddress address);
void SW_Int_4_Stop(void);

CY_ISR_PROTO(SW_Int_4_Interrupt);

void SW_Int_4_SetVector(cyisraddress address);
cyisraddress SW_Int_4_GetVector(void);

void SW_Int_4_SetPriority(uint8 priority);
uint8 SW_Int_4_GetPriority(void);

void SW_Int_4_Enable(void);
uint8 SW_Int_4_GetState(void);
void SW_Int_4_Disable(void);

void SW_Int_4_SetPending(void);
void SW_Int_4_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the SW_Int_4 ISR. */
#define SW_Int_4_INTC_VECTOR            ((reg32 *) SW_Int_4__INTC_VECT)

/* Address of the SW_Int_4 ISR priority. */
#define SW_Int_4_INTC_PRIOR             ((reg32 *) SW_Int_4__INTC_PRIOR_REG)

/* Priority of the SW_Int_4 interrupt. */
#define SW_Int_4_INTC_PRIOR_NUMBER      SW_Int_4__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable SW_Int_4 interrupt. */
#define SW_Int_4_INTC_SET_EN            ((reg32 *) SW_Int_4__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the SW_Int_4 interrupt. */
#define SW_Int_4_INTC_CLR_EN            ((reg32 *) SW_Int_4__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the SW_Int_4 interrupt state to pending. */
#define SW_Int_4_INTC_SET_PD            ((reg32 *) SW_Int_4__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the SW_Int_4 interrupt. */
#define SW_Int_4_INTC_CLR_PD            ((reg32 *) SW_Int_4__INTC_CLR_PD_REG)



#endif /* CY_ISR_SW_Int_4_H */


/* [] END OF FILE */
