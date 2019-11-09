#include <avr/io.h>
#include <util/delay.h>
#include "_main.h"
#include "_glcd.h"
#include "_adc.h"

unsigned int Data_ADC0 = 0;
unsigned int Data_ADC3 = 0;
unsigned int Data_ADC4 = 0;
unsigned int Data_ADC5 = 0;
unsigned int Data_ADC6 = 0;
unsigned int DATA_ADC7 = 0;
unsigned char Korean_buffer[32];

char Dis_Scr1[]={"===================="};
char Dis_Scr2[]={" INHA UNIVERSITY "};
char Dis_Scr_IO_ON[]={"O"};
char Dis_Scr_IO_OFF[]={"X"};

void Port_init(void){
	PORTA=0x00;   DDRA=0xFF;
	PORTB=0xFE;      DDRB=0b111111110;
	PORTC=0x00;      DDRC=0xF0;
	PORTD=0x80;      DDRD=0b10000000;
	PORTE=0x00;      DDRE=0xFF;
	PORTF=0x00;      DDRF=0x00;
}

void init_devices(void){
	cli();
	Port_init();
	lcd_init();
	Adc_init();
	sei();
}

int main(void)
{
	init_devices();
	lcd_clear();
	lcd_string(0,0,Dis_Scr1);
	lcd_string(1,0,Dis_Scr2);
	lcd_string(2,0,Dis_Scr1);

	/*GLCD_Circle(35, 55, 5);

	lcd_xy(4, 12);
	GLCD_4DigitDecimal(1234);*/

	while (1)
	{
		/*Data_ADC0 = Read_Adc_Data(0) / 10; //0번 아날로그 포트 읽기
		_delay_ms(200);
		lcd_clear();
		ScreenBuffer_clear();
		lcd_string(3, 0, "ADC 0");
		GLCD_Rectangle(70, 0, 80, Data_ADC0);
		lcd_xy(4, 0);
		GLCD_4DigitDecimal(Data_ADC0);*/

		/*Data_ADC3 = Read_Adc_Data(3) / 14;
		Data_ADC4 = Read_Adc_Data(4) / 8;
		_delay_ms(200);
		lcd_clear();
		ScreenBuffer_clear();
		lcd_string(0, 0, "ADC3, ADC4 JOYSTICK");
		GLCD_Line(32, 0, 31, 127);
		GLCD_Line(0, 63, 63, 63);
		GLCD_Circle(Data_ADC3, Data_ADC4, 5);*/

		Data_ADC5 = Read_Adc_Data(5) - 352 + 32;
		Data_ADC6 = Read_Adc_Data(6) - 358 + 62;
		DATA_ADC7 = Read_Adc_Data(7);
		_delay_ms(300);

		lcd_clear();
		ScreenBuffer_clear();

		lcd_xy(1, 0); GLCD_4DigitDecimal(Data_ADC5);
		lcd_xy(2, 0); GLCD_4DigitDecimal(Data_ADC6);
		lcd_xy(3, 0); GLCD_4DigitDecimal(DATA_ADC7);

		lcd_string(0, 0, "ADC5, ADC6 Acceleration");
		GLCD_Line(32, 0, 31, 127);
		GLCD_Line(0, 63, 63, 63);
		GLCD_Circle(Data_ADC5, Data_ADC6, 5);
		GLCD_Circle(32, 62, 5);
	}
}
