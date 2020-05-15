/*
* SevenSegment.c
*
* Created: 5/11/2020 2:22:20 PM
*  Author: user
*/

#include "SevenSegent.h"

extern volatile char flag;
extern int team_a_score;
extern int team_b_score;
void SS_INIT(){
	LCD_INIT();
	LCD_STRING("Let's Play Game");
	LCD_StringPos(2 , 0 , "---Start Now---");
}


void show_Timer(int *A_try , int *B_Try){

	for(int count = 0; count <= 9 ; count++){
		for(int data = 0; data <= 9 ; data++){
			if(flag == 1){
				INIT_TeamA(A_try);
				flag = 0;
			}
			if(flag == 2){
				INIT_TeamB(B_Try);
				flag = 0;
			}
			TSeg_Data_PORT = (TSeg_Data_PORT & (0x0F))|(data<<4);
			DIO_WriteChannel(TEN1 , STD_Higt);
			_delay_ms(5);
			DIO_WriteChannel(TEN1 , STD_Low);
			TSeg_Data_PORT = (TSeg_Data_PORT & (0x0F))|(count<<4);
			DIO_WriteChannel(TEN2 , STD_Higt);
			_delay_ms(10);
			DIO_WriteChannel(TEN2 , STD_Low);
		}
		if (count == 9)
		{
			if (team_a_score > team_b_score){
				LCD_CLEAR();
				LCD_STRING("Winner:Team A :D");
			}else if (team_b_score > team_a_score){
				LCD_CLEAR();
				LCD_STRING("Winner:Team B :D");
			}else{
				LCD_CLEAR();
				LCD_STRING("Equal:Play Again");

			}
		}
		_delay_ms(5);
	}

}

void INIT_TeamA(int *A_Try){
	DIO_WriteChannel(AEN2 , STD_Low);
	DIO_WriteChannel(AEN1 , STD_Low);
	if (A_Try[0] == 0)
	{
		TSeg_Data_PORT = (TSeg_Data_PORT & (0xF0))|(A_Try[0]);
		DIO_WriteChannel(AEN2 , STD_Higt);
		_delay_ms(5);
		DIO_WriteChannel(AEN2 , STD_Low);
		
		
		TSeg_Data_PORT = (TSeg_Data_PORT & (0xF0))|(A_Try[1]);
		DIO_WriteChannel(AEN1 , STD_Higt);
		_delay_ms(5);
	}else{
		TSeg_Data_PORT = (TSeg_Data_PORT & (0xF0))|(A_Try[1]);
		DIO_WriteChannel(AEN1 , STD_Higt);
		_delay_ms(5);
		DIO_WriteChannel(AEN1 , STD_Low);
		
		
		TSeg_Data_PORT = (TSeg_Data_PORT & (0xF0))|(A_Try[0]);
		DIO_WriteChannel(AEN2 , STD_Higt);
		_delay_ms(5);
	}
	
}
void INIT_TeamB(int *B_Try){
	DIO_WriteChannel(BEN2 , STD_Low);
	DIO_WriteChannel(BEN1 , STD_Low);
	if(B_Try[0] == 0){
		BSeg_Data_PORT = (BSeg_Data_PORT & (0x0F))|(B_Try[0]<<4);
		DIO_WriteChannel(BEN2 , STD_Higt);
		_delay_ms(5);
		DIO_WriteChannel(BEN2 , STD_Low);
		
		
		BSeg_Data_PORT = (BSeg_Data_PORT & (0x0F))|(B_Try[1]<<4);
		DIO_WriteChannel(BEN1 , STD_Higt);
		_delay_ms(5);
	}else{
		BSeg_Data_PORT = (BSeg_Data_PORT & (0x0F))|(B_Try[1]<<4);
		DIO_WriteChannel(BEN1 , STD_Higt);
		_delay_ms(5);
		DIO_WriteChannel(BEN1 , STD_Low);
		
		
		BSeg_Data_PORT = (BSeg_Data_PORT & (0x0F))|(B_Try[0]<<4);
		DIO_WriteChannel(BEN2 , STD_Higt);
		_delay_ms(5);
	}
}


int firstDigit(int a)
{
	while (a >= 10){
		a /= 10;
	}
	return a;
}

int lastDigit(int a)
{
	return (a % 10);
}

int getCount(int a){
	int count = 0;
	while (a != 0) {
		a /= 10;
		++count;
	}
	return count;
}
