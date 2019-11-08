/*
 * game_graphic_ex.c
 *
 * Created: 2019-11-07 오후 8:54:40
 * Author : yunso
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include "_glcd.h"
#include "_main.h"
#include "_bitmap.h"

void Port_init(void) 						// 포트 초기화 구문입니다.
{
	PORTA = 0x00; 	DDRA = 0xFF;			// PORTA 출력 LOW ,핀의 출력 설정
	PORTB = 0xFE; 	DDRB = 0xFF;			// PORTB 출력 LOW ,핀의 출력 설정
	PORTC = 0x00; 	DDRC = 0xF0;			// PORTC 상위 4bit 입력, 하위 4bit 출력
	PORTD = 0x80;	DDRD = 0x80;		// 핀의 입출력 설정
	PORTE = 0x00; 	DDRE = 0xFF;			// PORTE 출력 LOW ,핀의 출력 설정
	PORTF = 0x00; 	DDRF = 0x00;			// PORTE 출력 LOW ,핀의 출력 설정
}

int main(void)
{
	Port_init();
	lcd_init();
	lcd_clear();
	ScreenBuffer_clear();
    /* Replace with your application code */
    while (1) 
    {
		setHouse();
		setweapon();
		hpline();
		setplayer();
		home_Enemy_Character(10, 20);
    }
}

