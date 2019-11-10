/*
 * Timer1.c
 *
 * Created: 2019-10-29 오후 2:12:50
 * Author : yunso
 */ 

#include <avr/io.h>
#define F_CPU 14745600UL
//#include <util/dalay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "_main.h"
#include "_glcd.h"

unsigned char led = 0xfe;
unsigned char cnt;
int count;
unsigned char set;
unsigned char Temp = 0;

//인터럽트 발생 주기 1/(14.7456 MHz) * 1024 분주 * 256 = 17.8 ms
// 17.8 ms * 56 = 1 sec // 10/29

void Init_Timer0(void) {
	/*TCCR0 = 0x07; //0000 0111, normal mode, 프리스케일 1024
	TCNT0 = 0x00;
	SREG = 0x80;
	TIMSK = 0x01; //TOIE0 = 1 */ // 10/29

	TCCR0 = 0x6f; // 0110 1111 -> 1024분주 고속 PWM
	DDRB = 0x10; // 0001 0000 -> PORTB의 4번출력으로 설정 OC0핀
	OCR0 = 0xf0; 
	TCNT0 = 0x00;
	TIMSK |= (1 << OCIE0); // 출력비교 인터럽트 허가
}
//INT 0 // 10/29

ISR(/*TIMER0_OVF_vect // 10/29 */ TIMER0_COMP_vect) {
	SetBit(PORTB, PORTB4);

	/*cnt++;
	if(cnt == 56) { //1sec?
		count++;
		lcd_string(6, 1, "TIMER(SEC) : ");
		lcd_xy(6, 14);
		GLCD_4DigitDecimal(count);
		led <<= 1;
		led |= 0x01;
		if(led == 0xff)
			led = 0xfe;
		PORTB = led;
		cnt = 0;
		if(count >= 255) count = 0;
	}*/ // 10/29
}

void Port_init(void) {
	PORTA = 0x00;	DDRA = 0xff;
	PORTB = 0xff;	DDRB = 0xff;
	PORTC = 0x00;	DDRC = 0xf0;
	//PORTD = 0x80;	DDRD = 0x80; // 10/29
	PORTD = 0x00;	DDRD = 0x00;
	PORTE = 0x00;	DDRE = 0xff;
	//PORTF = 0x00;	DDRF = 0xf0; // 10/29
	PORTF = 0x00;	DDRF = 0x00;
} //보드에서 포트별로 설정

void init_devices(void) {
	cli(); //disable all interrupt
	Port_init();
	lcd_init();
	sei(); //re_enable interrupt
}
//screen 표시 

void screen_display(void) {
	lcd_clear(); // 그래픽 LCD 지우기
	lcd_string(0, 0, "========================");
	//lcd_string(1, 0, "*		 TIMER TEST		 *"); // 10/29
	lcd_string(1, 0, "*		 PWM TEST		 *");
	lcd_string(2, 0, "========================");
}

int main(void)
{
    /*init_devices();
	screen_display();
	Init_Timer0();*/ // 10/29

	unsigned char ch;
	int i;
	Temp = 0;
	init_devices();
	screen_display();
	Init_Timer0();
	Port_init();
	SREG |= 0x80;
	PIND = 0xff;
	PORTB = 0x20; // 모터 컨트롤러 제어 0010 0000 PORTB 5 = 1, 6 = 0 -> forward 
    while (1) 
    {
		PORTB = 0xff;
		ch = (PIND & 0xf0); // 스위치 입력 값 비교하기 위한 데이터 저장
		switch(ch) {
			PORTB = 0x00;
			_delay_ms(200);
			case 0xe0: // PORTB 7 스위치가 선택된 경우
				OCR0 = 0x01;
			break;
			case 0xd0: // PORTB 6 스위치가 선택된 경우
				OCR0 = 0x8f;
			break;
			case 0xb0: // PORTB 5 스위치가 선택된 경우
				OCR0 = 0xfd;
			break;
			default:
			break;
		}
    }
}


