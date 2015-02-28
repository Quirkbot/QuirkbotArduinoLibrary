#ifndef CommonNodeIncludes_h_
#define CommonNodeIncludes_h_

// The right side of the backback has the following adressable pins:

#define BP1 6    // Back Pack 1    (PD7)    ADC10    PWM (HS)    Uppmost left
#define BP2 12   // Back Pack 2    (PD6)    ADC9
#define BP3 0    // Back Pack 3    (PD2)    RXD1
#define BP4 2    // Back Pack 4    (PD1)    SDA
#define BP5 3    // Back Pack 5    (PD0)    SCL
#define BP6 1    // Back Pack 6    (PD3)    TXD1

// The mounth is only accessable through port manipulation:

#define TX_LED_ON() PORTD |= (1<<5)      // Left Mounth LED ON    (PD5)
#define TX_LED_OFF()  PORTD &= ~(1<<5)   // Left Mounth LED OFF
#define RX_LED_ON() PORTB |= (1<<0)      // Right Mounth LED ON   (PB0)
#define RX_LED_OFF()  PORTB &= ~(1<<0)   // Right Mounth LED OFF

// These constants are just for ease of use:

#define LM 101    // Left Mouth       (PD5) 
#define RM 102    // Right Mouth      (PB0) 


// Definitions for the eyes and the and the limbs:

#define LE 8     // Left Eye          (PB4)    ADC11
#define RE A5    // Right Eye         (PF0)    ADC0


#define LLF 9    // Left Leg Front    (PB5)    ADC12    PWM (16BIT)
#define RLF 11   // Right Leg Front   (PB7)             PWM (8/16BIT)
#define RAF 5    // Right Arm Front   (PC6)             PWM (HS)
#define HF 13    // Horn Front        (PC7)             PWM (10BIT)
#define LAF 10   // Left Arm Front    (PB6)    ADC13    PWM (16BIT)

#define LL LLF
#define RL RLF
#define RA RAF
#define H HF
#define LA LAF

#define LLB A0   // Left Leg Back     (PF7)    ADC7
#define RLB A4   // Right Leg Back    (PF1)    ADC1
#define RAB A3   // Right Arm Back    (PF4)    ADC4
#define HB A2    // Horn Back         (PF5)    ADC5
#define LAB A1   // Left Arm Back     (PF6)    ADC6

#include "Arduino.h"
#include "Bot.h"
#include "Node.h"
#include "Input.h"
#include "Output.h"
#include "HasIn.h"
#include "HasOut.h"
#include "HasInterval.h"
#include "HasInputCollection.h"
#include "HasTrigger.h"

#endif
