/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
    extern "C" {
#endif /* __cplusplus */

#define TIMER0_INT_InterruptFlagClear()       (INTCONbits.TMR0IF = 0)

#define TIMER0_INT_InterruptDisable()     (INTCONbits.TMR0IE = 0)

#define TIMER0_INT_InterruptEnable()     (INTCONbits.TMR0IE = 1)    

    //0 = Internal instruction cycle clock (FOSC/4)
#define TIMER0_clk_cycle_clock_FOSC_DIV_4()          (OPTION_REGbits.T0CS = 0)

#define TIMER0_prescaler_256() (OPTION_REGbits.PS = 7)    
#define TIMER0_prescaler_PS2_set() (OPTION_REGbits.PS2 = 1)
#define TIMER0_prescaler_PS1_set() (OPTION_REGbits.PS1 = 1)
#define TIMER0_prescaler_PS0_set() (OPTION_REGbits.PS1 = 1) 

#define TIMER0_prescaler_PS2_reset() (OPTION_REGbits.PS2 = 0)
#define TIMER0_prescaler_PS1_reset() (OPTION_REGbits.PS1 = 0)
#define TIMER0_prescaler_PS0_reset() (OPTION_REGbits.PS1 = 0)     

#define TIMER0_prescaler_enabled() (OPTION_REGbits.PSA = 0)  
#define TIMER0_prescaler_disabled() (OPTION_REGbits.PSA = 1)   

void TIMER0_ISR(void);
void TIMER0_INT_Initialize(void);    
/**
  @Summary
    Sets the edge detect of the external interrupt to positive edge.

  @Description
    This routine set the edge detect of the extern interrupt to positive edge.  
    After this routine is called the interrupt flag will be set when the external 
    interrupt pins level transitions from a low to high level.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    Setting the external interrupt to handle positive edge interrupts
    <code>
    // set the edge
    EXT_INT_fallingEdgeSet();
    // clear the interrupt flag and enable the interrupt
    EXT_INT_InterruptFlagClear();
    EXT_INT_InterruptEnable();
    </code>


//#ifdef	__cplusplus
}
//#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

