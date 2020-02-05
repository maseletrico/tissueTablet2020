
#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include "timer0_int.h"
#include "../TissueTablet.X/mcc_generated_files/pin_manager.h"

extern unsigned int timer0counter,count100ms; 
extern bool AD_GET,MOTOR_ON,INIT_OK,DELAY,BLINK_LED,LOW_BATTERY;
//uint8_t MOTOR_ON=0;
uint8_t warmupCounter =0;
uint8_t motorOnCount=0;
extern uint8_t delay20s;

// INTn Dynamic Interrupt Handlers 
void (*INT_InterruptHandler)(void);

void TIMER0_ISR(void)
{
    //***User Area Begin->code***
    timer0counter++;
    if(timer0counter==12){
        count100ms++;
        timer0counter=0;
        AD_GET=true;
        //OptoLed=!OptoLed;
        //IrLed=!IrLed;
    }
    //Inertval between dispenser
    if(BLINK_LED && count100ms==0){
        greenLed =1;

    }else{
       greenLed =0; 
    }
  
    //Low Battery
    if(LOW_BATTERY && count100ms==2){
        redLed =1;

    }else{
       redLed =0; 
    }
    
    
    
    if(count100ms==10){
         if(INIT_OK==false){
            redLed =! redLed;
         }
         count100ms=0;
         motorOnCount++;
         warmupCounter++;
         delay20s++;
         //greenLed=!greenLed;
        
    }
    
    if(warmupCounter==6 && INIT_OK==false){
        INIT_OK=true;
        warmupCounter=0;

    }
    
    //***User Area End->code***
    TIMER0_INT_InterruptFlagClear();
   
    // Callback function gets called everytime this ISR executes
    //INT_CallBack();    
}

void TIMER0_INT_Initialize(){
    TIMER0_INT_InterruptFlagClear();
    TIMER0_clk_cycle_clock_FOSC_DIV_4();
    TIMER0_prescaler_enabled();
    TIMER0_prescaler_PS0_set();
    TIMER0_prescaler_PS1_reset();
    TIMER0_prescaler_PS2_set();
    TIMER0_INT_InterruptEnable();
}
