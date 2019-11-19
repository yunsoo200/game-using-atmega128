/*
 * buzzer.c
 *
 * Created: 2017-11-14 오후 3:59:12
 * Author : inha00
 */ 

#include <avr/io.h>
#define F_CPU 14745600
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "_main.h"
#include "_buzzer.h"

int main(void)
{
    DDRD = 0x00;
	S_Start();
    while (1) 
    {
		char key;
		key = (PIND & 0xFF);
		switch(key) {
			case 0xFE:
				S_S1();
				break;
			case 0xFD:
				Same();
				break;
		}
		_delay_ms(100);
    }
}

