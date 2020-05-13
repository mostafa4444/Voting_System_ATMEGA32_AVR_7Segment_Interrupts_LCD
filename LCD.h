
#ifndef LCD_H_
#define LCD_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include "DIO_CFG.h"

#define LCD_Data_Port DIO_PORTC
#define LCD_Data_Dir DDRC_Reg

#define LCD_Control_Port DIO_PORTC
#define LCD_Control_Dir DDRC_Reg

#define LCD_RS DIO_ChannelC0
#define LCD_RW DIO_ChannelC1
#define LCD_E DIO_ChannelC2

void LCD_INIT(void);
void LCD_COMMAND(uint8 cmd);
void LCD_Char(uint8 data);
void LCD_STRING(char * string);
void LCD_CharPos(uint8 line , uint8 pos , uint8 data);
void LCD_StringPos(uint8 line , uint8 pos , char * string);
void LCD_SPChar(uint8 loc , char * msg);
void LCD_CLEAR(void);
#endif /* LCD_H_ */