#ifndef Board_h_
#define Board_h_

#ifndef QUIRKBOT_BOARD_VARIANT

// BOARD LOCATIONS -------------------------------------------------------------

// No Location 
#define NO_LOCATION	0

// Built in LEDs
#define LM	106	// Left Mouth		(PD5) 
#define RM	107	// Right Mouth		(PB0) 
							
#define LE	8	// Left Eye		 	(PB4)	ADC11
#define RE	A5	// Right Eye		(PF0)	ADC0
							
// Limbs
#define LL	100	// Left Leg
#define RL	101	// Right Leg
#define RA	102	// Right Arm
#define H	103	// Horn
#define LA	105	// Left Arm
							
#define LLF	9	// Left Leg Front	(PB5)	ADC12	PWM (16BIT)
#define RLF	11	// Right Leg Front	(PB7)			PWM (8/16BIT)
#define RAF	5	// Right Arm Front	(PC6)			PWM (HS)
#define HF	13	// Horn Front		(PC7)			PWM (10BIT)
#define LAF	10	// Left Arm Front	(PB6)	ADC13	PWM (16BIT)
						
#define LLB	A0	// Left Leg Back	(PF7)	ADC7
#define RLB	A4	// Right Leg Back	(PF1)	ADC1
#define RAB	A3	// Right Arm Back	(PF4)	ADC4
#define HB	A2	// Horn Back		(PF5)	ADC5
#define LAB	A1	// Left Arm Back	(PF6)	ADC6

// Backpack
#define BP1	6	// Back Pack 1		(PD7)	ADC10	PWM (HS)	Uppmost left
#define BP2	12	// Back Pack 2		(PD6)	ADC9
#define BP3	0	// Back Pack 3		(PD2)	RXD1
#define BP4	2	// Back Pack 4		(PD1)	SDA
#define BP5	3	// Back Pack 5		(PD0)	SCL
#define BP6	1 	// Back Pack 6		(PD3)	TXD1


// RX and TX -------------------------------------------------------------------
// Keep off when doing serial communication
#undef TXLED0
#undef TXLED1
#undef RXLED0
#undef RXLED1
#define TXLED0		PORTD &= ~(1<<5)
#define TXLED1		PORTD &= ~(1<<5)
#define RXLED0		PORTB &= ~(1<<0)
#define RXLED1		PORTB &= ~(1<<0)

#endif

#endif