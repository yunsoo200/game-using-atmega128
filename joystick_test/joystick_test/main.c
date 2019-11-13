/*
 * joystick_test.c
 *
 * Created: 2019-11-13 오후 1:39:48
 * Author : yunso
 */ 

#include <avr/io.h>
#include "_main.h"
#include "_glcd.h"
#include <util/delay.h>

unsigned int Data_ADC3 = 0; // 조이스틱 상하 데이터 값 저장용
unsigned int Data_ADC4 = 0; // 조이스틱 좌우 데이터 값 저장용

#define ADC_VREF_TYPE 0x00; // ADC 컨버터 사용 기준 전압 REFS 설정
#define ADC_AVCC_TYPE 0x40; // ADC 컨버터 사용 기준 전압 AVCC 설정
#define ADC_RES_TYPE 0x80; // ADC 컨버터 사용 기준 전압 RES 설정
#define ADC_2_56_TYPE 0xC0; // ADC 컨버터 사용 기준 전압 2.56 설정

// ADC 초기화
void Adc_init(void) {
	ADCSRA = 0x00; // disable adc
	ADMUX = 0x00; // select adc input 0
	ACSR = 0x80; // 1000 0000
	ADCSRA = 0xC3; // 1100 0011
}

// ADC 값 읽는 부분
unsigned int Read_Adc_Data(unsigned char adc_input) {
	unsigned int adc = 0;
	ADCSRA = 0xC3;
	ADMUX = adc_input | ADC_AVCC_TYPE; // ADC 사용핀 설정
	ADCSRA |= 0x40; // 0100 0000 wait for the AD conversion to complete
	while((ADCSRA & 0x10) != 0x10); // 0001 0000
	adc += ADCL + (ADCH * 256);
	ADCSRA = 0x00;
	return adc;
}

void Port_init() {
	PORTA = 0x00;	DDRA = 0xFF;
	PORTB = 0xFF;	DDRB = 0xFF;
	PORTC = 0x00;	DDRC = 0xF0;
	PORTD = 0x80;	DDRD = 0x80;
	PORTE = 0x00;	DDRE = 0xFF;
	PORTF = 0x00;	DDRF = 0x00;
}
void init_devices() {
	cli(); // 인터럽트 disable
	Port_init();
	Adc_init();
	lcd_init();
	sei(); // 인터럽트 enable
}

void screen_display(void) {
	lcd_clear();
	lcd_string(0, 0, "===============");
	lcd_string(1, 0, "*JOYSTICK TEST*");
	lcd_string(2, 0, "===============");
}

void LCD_Decimal(unsigned char num, short AD_dat) {
	unsigned char Decimal[5];
	Decimal[4] = AD_dat/10000; // 10000의 자리 아스키 값으로 저장
	AD_dat = AD_dat % 10000;

	Decimal[3] = AD_dat/1000; // 1000의 자리 아스키 값으로 저장
	AD_dat = AD_dat % 1000;

	Decimal[2] = AD_dat/100; // 100의 자리 아스키 값으로 저장
	AD_dat = AD_dat % 100;

	Decimal[1] = AD_dat/10; // 10의 자리 아스키 값으로 저장
	AD_dat = AD_dat % 10;

	Decimal[0] = AD_dat; // 1의 자리 아스키 값으로 저장

	if(num == 0) { // data_adc3 변환
		lcd_xy(5, 11); GLCD_1DigitDecimal(Decimal[4], 1); // 10000 자리 출력
		lcd_string(5, 12, ".");
		lcd_xy(5, 13); GLCD_1DigitDecimal(Decimal[3], 1); // 1000 자리 출력
		lcd_xy(5, 14); GLCD_1DigitDecimal(Decimal[2], 1); // 100 자리 출력
		lcd_xy(5, 15); GLCD_1DigitDecimal(Decimal[1], 1); // 10 자리 출력
		lcd_xy(5, 16); GLCD_1DigitDecimal(Decimal[0], 1); // 1 자리 출력
	}
	if(num == 1) { // data_adc4 변환
		lcd_xy(7, 11); GLCD_1DigitDecimal(Decimal[4], 1); // 10000 자리 출력
		lcd_string(7, 12, ".");
		lcd_xy(7, 13); GLCD_1DigitDecimal(Decimal[3], 1); // 1000 자리 출력
		lcd_xy(7, 14); GLCD_1DigitDecimal(Decimal[2], 1); // 100 자리 출력
		lcd_xy(7, 15); GLCD_1DigitDecimal(Decimal[1], 1); // 10 자리 출력
		lcd_xy(7, 16); GLCD_1DigitDecimal(Decimal[0], 1); // 1 자리 출력
	}
}

void joystick_move_menu(void) {
	short Voltage1 = 0;
	short Voltage2 = 0;
	Data_ADC3 = Read_Adc_Data(3) / 14;
	Data_ADC4 = Read_Adc_Data(4) / 8;
	_delay_ms(30);
	lcd_string(3, 0, "               ");
	// 상하 : 메뉴이동, 좌우 : 메뉴선택
	if(Data_ADC3 > 50) { // 좌(<--) 조작
		lcd_string(3, 0, "LEFT           ");
		_delay_ms(300);
	}
	else if(Data_ADC3 < 20) { // 우(-->) 조작
		lcd_string(3, 0, "RIGHT          ");
		_delay_ms(300);
	}
	else if(Data_ADC4 > 90) { // 하 조작
		lcd_string(3, 0, "DOWN           ");
		_delay_ms(300);
	}
	else if(Data_ADC4 < 20) { // 상 조작
		lcd_string(3, 0, "UP             ");
		_delay_ms(300);
	}
	else lcd_string(3, 0, "               ");
	// ADC 값 화면 출력
	lcd_string(4, 1, "Data_ADC3 : ");
	lcd_xy(4, 11);
	GLCD_4DigitDecimal(Data_ADC3);

	lcd_string(5, 1, "Data_ADC3 V : ");
	Voltage1 = (short)((0.025 * Data_ADC3) * 10000); // AD를 전압으로 변환
	LCD_Decimal(0, Voltage1);

	lcd_string(6, 1, "Data_ADC4 : ");
	lcd_xy(6, 11);
	GLCD_4DigitDecimal(Data_ADC4);

	lcd_string(7, 1, "Data_ADC4 V : ");
	Voltage2 = (short)((0.025 * Data_ADC4) * 10000); // AD를 전압으로 변환
	LCD_Decimal(1, Voltage2);
}

int score = 0;
void tmp_game() {
	
	lcd_string(7, 0, "----------------------------------------");
}

int main(void)
{
	init_devices();
	screen_display();
    while (1) 
    {
		//joystick_move_menu();
		tmp_game();
    }
}

//알파벳이 떨어지고 조이스틱으로 그 알파벳을 먹는 게임 만들어보기