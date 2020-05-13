/*
 * SevenSegent.h
 *
 * Created: 5/11/2020 2:14:46 PM
 *  Author: user
 */ 


#ifndef SEVENSEGENT_H_
#define SEVENSEGENT_H_

 
#include "DIO_CFG.h"
#include "Bit_Math.h"
#include "LCD.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#define TSeg_Data_DDR DDRA_Reg
#define TSeg_Data_PORT PORTA_Reg
#define TSeg_Control_DDR DDRB_Reg
#define TSeg_Control_PORT PORTB_Reg

#define TEN2 DIO_ChannelB1
#define TEN1 DIO_ChannelB0
#define TDP  DIO_ChannelB3


void SS_INIT();
void show_Timer();
void INIT_TeamA();
void INIT_TeamB();
void INIT_Interrupts();
void start_interrupts();
int firstDigit(int a);
int lastDigit(int a);
int getCount(int a);
//---------- Team A ------------

#define ASeg_Data_DDR DDRA_Reg
#define ASeg_Data_PORT PORTA_Reg
#define ASeg_Control_DDR DDRB_Reg
#define ASeg_Control_PORT PORTB_Reg

#define AEN2 DIO_ChannelB5
#define AEN1 DIO_ChannelB4
#define ADP  DIO_ChannelB6

//---------------Team B------------------------------
#define BSeg_Data_DDR DDRD_Reg
#define BSeg_Data_PORT PORTD_Reg
#define BSeg_Control_DDR DDRD_Reg
#define BSeg_Control_PORT PORTD_Reg

#define BEN2 DIO_ChannelD1
#define BEN1 DIO_ChannelD0
#define BDP  DIO_ChannelD2


#endif /* SEVENSEGENT_H_ */