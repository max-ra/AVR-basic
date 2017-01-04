/*
 * DemoProjekt LED.c
 *
 * Created: 04.01.2017 15:22:40
 * Author : maxi
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect);

ISR(INT0_vect){
	PORTD ^= (1<<PD6);
} 


int main(void)
{

	//Ausgänge vorbereiten 
	DDRD = 0xff;

	//Eingänge für Taste
	DDRD &= ~(1<<PD2) & ~(1<<PD3) & ~(1<<PD4);

	//Init Zähler




	//Init Interrupt 
	DDRD &= ~(1<<PD2);						//Eingang Setzten
	MCUCR |= ((1<<ISC01) | (1<<ISC00));		//Steigende Flanke

	GICR |= (1<<INT0);

	sei();									//Global alle Interrupts freigeben
	
	//cli();								//Global alle Interrupts sperren

    /* Replace with your application code */
    while (1) 
    {
	
		if (PIND &  (1<<PD4))
		{
					//LED EIN
		PORTD |= (1<<PD5);
		}


		if (PIND & (1<<PD3))
		{
			//LED AUS
		PORTD &= ~(1<<PD5);
		}

	

    }
}

