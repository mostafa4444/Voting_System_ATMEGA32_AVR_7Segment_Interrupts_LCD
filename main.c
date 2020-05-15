/*
 * Voting.c
 *
 * Created: 5/11/2020 1:55:05 PM
 * Author : user
 */ 

#include "SevenSegent.h"


volatile char flag = 0;
int team_a_score = 0;
int team_b_score = 0;
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



int main(void)
{
	INIT_TeamA(A_Try);
	INIT_TeamB(B_Try);
    SS_INIT();
	GICR |= (1<<7) | (1<<5);
	MCUCR |= (1<<ISC10) | (1<<ISC11);
	MCUCSR |= (1<<ISC2);
	//Set_Bit(GICR , 7);
	//Set_Bit(GICR , 5);
	//Set_Bit(MCUCR , 2);
	//Set_Bit(MCUCR , 3);
	//Set_Bit(MCUCSR , 6);
	sei();
	
    while (1) 
    {
		 show_Timer( A_Try , B_Try);
		 break;

	}
}
