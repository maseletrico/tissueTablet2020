/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC16F1709
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include <stdbool.h>

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/adc.h"

unsigned int timer0counter=0, count100ms=0;
bool AD_GET=false,MOTOR_ON=false,INIT_OK=false,DELAY=false,BLINK_LED=false;
bool LOW_BATTERY=false;
uint16_t resultadoAD=0,mediaMax=0;
uint16_t ADm1=0,ADm2=0,ADm3=0,ADm4=0,ADm5=0,ADm6=0,ADm7=0,ADm8=0,ADm9=0,ADmedia=0;
uint8_t adChanell = 0,delay20s;
extern bool warmupCounter;
extern uint8_t motorOnCount;
/*
                         Main application
 */
void main(void)
{
    
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    pinInit();
    
    while (1)
    {
        ADm9=1000;
        ADm8=1000;
        ADm7=1000;
        ADm6=1000;
        ADm5=1000;
        ADm4=1000;
        ADm3=1000;
        ADm2=1000;
        ADm1=1000;
        if(INIT_OK){
           if(AD_GET){

                AD_GET=false;
                adChanell = 4;
                resultadoAD = ADC_GetConversion(adChanell);
                ADm9 = ADm8;
                ADm8 = ADm7;
                ADm7 = ADm6;
                ADm6 = ADm5;
                ADm5 = ADm4;
                ADm4 = ADm3;
                ADm3 = ADm2;
                ADm2 = ADm1;
                ADm1 = resultadoAD;
                ADmedia=(resultadoAD+ADm9+ADm8+ADm7+ADm6+ADm5+ADm4+ADm3+ADm2+ADm1)/10;

                if(resultadoAD<=700){
                    MOTOR_ON = true;
                }
                if(mediaMax < ADmedia){
                    mediaMax=ADmedia;
                }
                //Low Battery Alarm 30% bellow 6V
                adChanell = 5;
                resultadoAD = ADC_GetConversion(adChanell);
                if(resultadoAD<=0x2CC){
                    LOW_BATTERY=true;
                }else{
                    LOW_BATTERY==false;
                }
    
            }
            if(MOTOR_ON){
                MOTOR_ON=false;
                motor=1;
                greenLed = 1;//Green Led on
                motorOnCount=0;
                while(motorOnCount<2){
                    
                } 
                
                motor=0;
                greenLed = 0;//Green Led off
                delay20s=0;
                while(delay20s<=10){
                   BLINK_LED=true;
               }
               BLINK_LED=false; 
               greenLed=0;

                       
            }
         
        }
    }
    
    
}

void pinInit(){
        greenLed = 0;//Green Led off 
        redLed = 0;//Green Led off 
        motor = 0; //Motor off
        IrLed = 0;
        OptoLed = 0;

    }
/**
 End of File
*/