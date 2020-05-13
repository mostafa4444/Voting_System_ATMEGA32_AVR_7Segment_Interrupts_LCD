/*
* SevenSegment.c
*
* Created: 5/11/2020 2:22:20 PM
*  Author: user
*/

#include "SevenSegent.h"
volatile char flag = 0;
int team_a_score = 28;
int team_b_score = 25;
int A_Try[2] = {0 , 0};
int B_Try[2] = {0 , 0};


ISR(INT2_vect){
	flag = 1;
	++team_a_score;
	if(getCount(team_a_score) > 1){
		A_Try[0] = firstDigit(team_a_score);
		A_Try[1] = lastDigit(team_a_score);
	}else{
		A_Try[0] = 0;
		A_Try[1] = team_a_score;
	}
}

ISR(INT1_vect){
	flag = 2;
	++team_b_score;
	if(getCount(team_b_score) > 1){
		B_Try[0] = firstDigit(team_b_score);
		B_Try[1] = lastDigit(team_b_score);
	}else{
		B_Try[0] = 0;
		B_Try[1] = team_b_score;
	}
}


void SS_INIT(){
	LCD_INIT();
	LCD_STRING("Let's Play Game");
	LCD_StringPos(2 , 0 , "---Start Now---");
	INIT_Interrupts();
}

void INIT_Interrupts(){
	//D3  B2
	Set_Bit(GICR , 7);
	Set_Bit(GICR , 5);
	Set_Bit(MCUCR , 0);
	Set_Bit(MCUCR , 1);
	sei();
}


void show_Timer(){

	for(int count = 0; count <= 9 ; count++){
		for(int data = 0; data <= 9 ; data++){
			if(flag == 1){
				INIT_TeamA();
				flag = 0;
			}
			if(flag == 2){
				INIT_TeamB();
				flag = 0;
			}
			TSeg_Data_PORT = (TSeg_Data_PORT & (0x0F))|(data<<4);
			DIO_WriteChannel(TEN1 , STD_Higt);
			_delay_ms(10);
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
		_delay_ms(10);
	}

}

void INIT_TeamA(){
	ASeg_Data_PORT = (ASeg_Data_PORT & (0xF0))|(A_Try[1]<<4);
	DIO_WriteChannel(AEN1 , STD_Higt);
	_delay_ms(10);
	DIO_WriteChannel(AEN1 , STD_Low);
	
	
	ASeg_Data_PORT = (ASeg_Data_PORT & (0xF0))|(A_Try[0]<<4);
	DIO_WriteChannel(AEN2 , STD_Higt);
	_delay_ms(10);
}
void INIT_TeamB(){
	
	BSeg_Data_PORT = (BSeg_Data_PORT & (0x0F))|(B_Try[1]<<4);
	DIO_WriteChannel(BEN1 , STD_Higt);
	_delay_ms(10);
	DIO_WriteChannel(BEN1 , STD_Low);
	
	
	BSeg_Data_PORT = (BSeg_Data_PORT & (0x0F))|(B_Try[0]<<4);
	DIO_WriteChannel(BEN2 , STD_Higt);
	_delay_ms(10);
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
