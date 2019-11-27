/*
 * Interept1.c
 *
 * Created: 2019-10-08 오후 1:53:41
 * Author : yunso
 */ 

/*#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include "_main.h"
#define F_CPU 14745600UL

char count;
SIGNAL(INT0_vect) {
	//ISR
	count++;
}
void Interrupt_init() {
	SREG |= 0x80;
	EICRA = 0x02; //INT 0의 F E 트리거
	EIMSK = 0x01; //INT 0만 허가
	DDRD=0x00; //INT 0~3은 PD 0~3
}
int main(void)
{
	Interrupt_init();
	DDRB=0xff;
	count=0;
	while(1) {
		PORTB = ~count;
		if(count >= 255) {count=0;}
	}
    
}*/

/*#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include "_main.h"
#define F_CPU 14745600UL

char exchange;
SIGNAL(INT0_vect) {
	//ISR
	exchange = ~exchange;
}
void Interrupt_init() {
	SREG |= 0x80;
	EICRA = 0x02; //INT 0의 F E 트리거
	EIMSK = 0x01; //INT 0만 허가
	DDRD=0x00; //INT 0~3은 PD 0~3
}
int main(void)
{
	Interrupt_init();
	DDRB=0xff;
	PORTB=0x00;
	exchange=0;
	while(1) {
		if(exchange) PORTB=0xff;
		else PORTB=0x00;
	}
}*/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include "_main.h"
#define F_CPU 14745600UL

char direction;
SIGNAL(INT0_vect) {
	//ISR
	direction = ~direction;
}
void Interrupt_init() {
	SREG |= 0x80;
	EICRA = 0x02; //INT 0의 F E 트리거
	EIMSK = 0x01; //INT 0만 허가
	DDRD=0x00; //INT 0~3은 PD 0~3
}
void PB_Lshift() {
	int i;
	char Temp;
	Temp = 0xFE;
	for(i = 0; i < 8; i++) {
		_delay_ms(500);
		PORTB = Temp;
		Temp = (Temp << 1) | 0x01;
	}
} //Lshift에서 8번 LED가 off임. why?
void PB_Rshift() {
	int i;
	char Temp;
	Temp = 0x7E;
	for(i = 0; i < 8; i++) {
		_delay_ms(500);
		PORTB = Temp;
		Temp = (Temp >> 1) | 0x80;
		PORTB = Temp;
	}
}
int main(void)
{
	Interrupt_init();
	DDRB=0xff;
	PORTB=0x0f;
	direction=0;
	while(1) {
		if(direction) PB_Lshift();
		else PB_Rshift();
	}
}

