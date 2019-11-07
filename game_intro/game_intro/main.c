/*
 * game_intro.c
 *
 * Created: 2019-11-07 오후 8:40:25
 * Author : yunso
 */ 

#include <avr/io.h>
#include "_main.h"
#include "_glcd2.h"
#include "bit_map_character2.h"

void Port_init(void) 						// 포트 초기화 구문입니다.
{
	PORTA = 0x00; 	DDRA = 0xFF;			// PORTA 출력 LOW ,핀의 출력 설정
	PORTB = 0xFE; 	DDRB = 0xFF;			// PORTB 출력 LOW ,핀의 출력 설정
	PORTC = 0x00; 	DDRC = 0xF0;			// PORTC 상위 4bit 입력, 하위 4bit 출력
	PORTD = 0x80;	DDRD = 0x80;		// 핀의 입출력 설정
	PORTE = 0x00; 	DDRE = 0xFF;			// PORTE 출력 LOW ,핀의 출력 설정
	PORTF = 0x00; 	DDRF = 0x00;			// PORTE 출력 LOW ,핀의 출력 설정
}

void init_device() {
	cli();
	Port_init();
	lcd_init();
	sei();
}

int main(void)
{
	init_device();
	//start 화면
	lcd_clear();
	ScreenBuffer_clear();
	glcd_draw_bitmap(start_title, 0, 0, 40, 72);
	lcd_string(7, 0, "< PRESS BUTTON 0 >");
    /* Replace with your application code */
    while (1) 
    {
		//사진을 converting해서 도트값을 받음
		glcd_draw_bitmap(start_lion1, 0, 75, 48, 48);
		_delay_ms(500);
		glcd_draw_bitmap(start_lion2, 0, 75, 48, 48);
		_delay_ms(500);
    }
}

