
#include <avr/io.h>
#define F_CPU 14745600UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "_main.h"
#include "_bitmap.h"


void setweapon(void)				//사용중인 무기 도트
{
	for(int i = 110; i<113; i++){
		GLCD_Dot(61,i);
	}
	for(int i = 110; i<111; i++){
		GLCD_Dot(60,i);
	}
	for(int i = 112; i<113; i++){
		GLCD_Dot(60,i);
	}
	for(int i = 108; i<111; i++){
		GLCD_Dot(59,i);
	}
	for(int i = 112; i<113; i++){
		GLCD_Dot(59,i);
	}
	for(int i = 107; i<108; i++){
		GLCD_Dot(58,i);
	}
	for(int i = 109; i<111; i++){
		GLCD_Dot(58,i);
	}
	for(int i = 112; i<114; i++){
		GLCD_Dot(58,i);
	}
	for(int i = 101; i<111; i++){
		GLCD_Dot(57,i);
	}
	for(int i = 112; i<114; i++){
		GLCD_Dot(57,i);
	}
	for(int i = 101; i<109; i++){
		GLCD_Dot(56,i);
	}
	for(int i = 113; i<114; i++){
		GLCD_Dot(56,i);
	}
	for(int i = 101; i<102; i++){
		GLCD_Dot(55,i);
	}
	for(int i = 108; i<114; i++){
		GLCD_Dot(55,i);
	}
	for(int i = 109; i<112; i++){
		GLCD_Dot(54,i);
	}
	//총 모형 끝
	for(int i =63 ; i>51; i--){
		GLCD_Dot(i,99);
		GLCD_Dot(i,127);
	}
	for(int i =99 ; i<128; i++){
		GLCD_Dot(52,i);
		GLCD_Dot(63,i);
	}
}
void home_Enemy_Character(unsigned int x, unsigned int y) // 지붕 위 적 캐릭터 도트
{
	GLCD_Dot(x-4,y-2);
	GLCD_Dot(x-4,y-1);
	GLCD_Dot(x-4,y);
	GLCD_Dot(x-4,y+5);
	GLCD_Dot(x-4,y+6);
	GLCD_Dot(x-4,y+7);
	
	GLCD_Dot(x-5,y-1);
	GLCD_Dot(x-5,y);
	GLCD_Dot(x-5,y+1);
	GLCD_Dot(x-5,y+2);
	GLCD_Dot(x-5,y+3);
	GLCD_Dot(x-5,y+4);
	GLCD_Dot(x-5,y+5);
	GLCD_Dot(x-5,y+6);

	GLCD_Dot(x-6,y-2);
	GLCD_Dot(x-6,y-1);
	GLCD_Dot(x-6,y+1);
	GLCD_Dot(x-6,y+4);
	GLCD_Dot(x-6,y+5);
	GLCD_Dot(x-6,y+6);
	GLCD_Dot(x-6,y+7);
	GLCD_Dot(x-6,y+8);
	GLCD_Dot(x-6,y+9);
	
	GLCD_Dot(x-7,y-3);
	GLCD_Dot(x-7,y-2);
	GLCD_Dot(x-7,y+1);
	GLCD_Dot(x-7,y+2);
	GLCD_Dot(x-7,y+3);
	GLCD_Dot(x-7,y+4);
	GLCD_Dot(x-7,y+7);
	GLCD_Dot(x-7,y+8);

	GLCD_Dot(x-8,y-3);
	GLCD_Dot(x-8,y-2);
	GLCD_Dot(x-8,y+7);
	GLCD_Dot(x-8,y+8);

	GLCD_Dot(x-9,y-3);
	GLCD_Dot(x-9,y-2);
	GLCD_Dot(x-9,y);
	GLCD_Dot(x-9,y+1);
	GLCD_Dot(x-9,y+4);
	GLCD_Dot(x-9,y+5);
	GLCD_Dot(x-9,y+7);
	GLCD_Dot(x-9,y+8);

	int i;
	for(i=-5; i<11; i++)
	{
		GLCD_Dot(x-10,y+i);
	}
	GLCD_Dot(x-11,y-5);
	GLCD_Dot(x-11,y+10);
	
	GLCD_Dot(x-12,y-5);
	GLCD_Dot(x-12,y-4);
	GLCD_Dot(x-12,y-3);
	GLCD_Dot(x-12,y-2);
	GLCD_Dot(x-12,y-1);
	GLCD_Dot(x-12,y+6);
	GLCD_Dot(x-12,y+7);
	GLCD_Dot(x-12,y+8);
	GLCD_Dot(x-12,y+9);
	GLCD_Dot(x-12,y+10);
	
	GLCD_Dot(x-13,y-1);
	GLCD_Dot(x-13,y);
	GLCD_Dot(x-13,y+1);
	GLCD_Dot(x-13,y+2);
	GLCD_Dot(x-13,y+3);
	GLCD_Dot(x-13,y+4);
	GLCD_Dot(x-13,y+5);
	GLCD_Dot(x-13,y+6);

	GLCD_Dot(x-14,y-1);
	GLCD_Dot(x-14,y+6);

	GLCD_Dot(x-15,y-1);
	GLCD_Dot(x-15,y);
	GLCD_Dot(x-15,y+1);
	GLCD_Dot(x-15,y+2);
	GLCD_Dot(x-15,y+3);
	GLCD_Dot(x-15,y+4);
	GLCD_Dot(x-15,y+5);
	GLCD_Dot(x-15,y+6);

}

void hpline(void)					//hp도트 외부 라인 도트
{
	for(int i = 0; i<34; i++){
		GLCD_Dot(63,i);
		GLCD_Dot(51,i);
	}
	for(int i = 63; i>51; i--){
		GLCD_Dot(i,0);
		GLCD_Dot(i,33);
	}
}

void setHouse(void)					//배경 - 집 도트
{
	int i;
	for(i=8; i<40; i++)
	{GLCD_Dot(45,i);}
	GLCD_Dot(44,8);
	GLCD_Dot(44,27);
	GLCD_Dot(44,34);
	GLCD_Dot(44,39);
	
	GLCD_Dot(43,8);
	GLCD_Dot(43,27);
	GLCD_Dot(43,34);
	GLCD_Dot(43,39);
	
	GLCD_Dot(42,8);
	GLCD_Dot(42,9);
	GLCD_Dot(42,10);
	GLCD_Dot(42,11);
	GLCD_Dot(42,21);
	GLCD_Dot(42,22);
	GLCD_Dot(42,23);
	GLCD_Dot(42,27);
	GLCD_Dot(42,34);
	GLCD_Dot(42,36);
	GLCD_Dot(42,37);
	GLCD_Dot(42,38);
	GLCD_Dot(42,39);
	
	GLCD_Dot(41,8);
	GLCD_Dot(41,10);
	GLCD_Dot(41,11);
	GLCD_Dot(41,22);
	GLCD_Dot(41,23);
	GLCD_Dot(41,27);
	GLCD_Dot(41,37);
	GLCD_Dot(41,38);
	GLCD_Dot(41,39);
	
	GLCD_Dot(40,8);
	GLCD_Dot(40,13);
	GLCD_Dot(40,14);
	GLCD_Dot(40,15);
	GLCD_Dot(40,16);
	GLCD_Dot(40,17);
	GLCD_Dot(40,18);
	GLCD_Dot(40,19);
	GLCD_Dot(40,20);
	GLCD_Dot(40,21);
	GLCD_Dot(40,22);
	GLCD_Dot(40,27);
	GLCD_Dot(40,34);
	GLCD_Dot(40,39);
	
	GLCD_Dot(39,8);
	GLCD_Dot(39,13);
	GLCD_Dot(39,22);
	GLCD_Dot(39,27);
	GLCD_Dot(39,34);
	GLCD_Dot(39,39);
	
	GLCD_Dot(38,8);
	GLCD_Dot(38,13);
	GLCD_Dot(38,22);
	GLCD_Dot(38,27);
	GLCD_Dot(38,29);
	GLCD_Dot(38,34);
	GLCD_Dot(38,39);
	
	GLCD_Dot(38,8);
	GLCD_Dot(38,13);
	GLCD_Dot(38,22);
	GLCD_Dot(38,27);
	GLCD_Dot(38,34);
	GLCD_Dot(38,39);
	
	GLCD_Dot(37,8);
	GLCD_Dot(37,13);
	GLCD_Dot(37,22);
	GLCD_Dot(37,27);
	GLCD_Dot(37,34);
	GLCD_Dot(37,39);
	
	GLCD_Dot(36,8);
	GLCD_Dot(36,13);
	GLCD_Dot(36,22);
	GLCD_Dot(36,27);
	GLCD_Dot(36,34);
	GLCD_Dot(36,39);
	
	GLCD_Dot(35,8);
	GLCD_Dot(35,13);
	GLCD_Dot(35,14);
	GLCD_Dot(35,21);
	GLCD_Dot(35,22);
	GLCD_Dot(35,27);
	GLCD_Dot(35,34);
	GLCD_Dot(35,35);
	GLCD_Dot(35,36);
	GLCD_Dot(35,37);
	GLCD_Dot(35,39);
	
	GLCD_Dot(34,8);
	GLCD_Dot(34,13);
	GLCD_Dot(34,14);
	GLCD_Dot(34,15);
	GLCD_Dot(34,22);
	GLCD_Dot(34,21);
	GLCD_Dot(34,20);
	GLCD_Dot(34,27);
	GLCD_Dot(34,34);
	GLCD_Dot(34,36);
	GLCD_Dot(34,37);
	GLCD_Dot(34,39);
	
	GLCD_Dot(33,8);
	GLCD_Dot(33,13);
	GLCD_Dot(33,14);
	GLCD_Dot(33,15);
	GLCD_Dot(33,16);
	GLCD_Dot(33,17);
	GLCD_Dot(33,18);
	GLCD_Dot(33,19);
	GLCD_Dot(33,20);
	GLCD_Dot(33,21);
	GLCD_Dot(33,22);
	GLCD_Dot(33,27);
	GLCD_Dot(33,34);
	GLCD_Dot(33,39);
	
	GLCD_Dot(32,8);


	GLCD_Dot(32,27);
	GLCD_Dot(32,28);
	GLCD_Dot(32,29);
	GLCD_Dot(32,30);
	GLCD_Dot(32,31);
	GLCD_Dot(32,32);
	GLCD_Dot(32,33);
	GLCD_Dot(32,34);
	GLCD_Dot(32,39);
	
	GLCD_Dot(31,8);
	GLCD_Dot(31,39);
	
	GLCD_Dot(30,8);
	GLCD_Dot(30,29);
	GLCD_Dot(30,30);
	GLCD_Dot(30,31);
	GLCD_Dot(30,39);
	
	GLCD_Dot(29,8);
	GLCD_Dot(29,31);
	GLCD_Dot(29,30);
	GLCD_Dot(29,39);
	
	GLCD_Dot(28,8);
	GLCD_Dot(28,16);
	GLCD_Dot(28,17);
	GLCD_Dot(28,18);
	GLCD_Dot(28,39);
	
	GLCD_Dot(27,8);
	GLCD_Dot(27,17);
	GLCD_Dot(27,18);
	GLCD_Dot(27,39);
	
	GLCD_Dot(26,8);
	GLCD_Dot(26,10);
	GLCD_Dot(26,11);
	GLCD_Dot(26,12);
	GLCD_Dot(26,33);
	GLCD_Dot(26,34);
	GLCD_Dot(26,35);
	GLCD_Dot(26,39);
	
	GLCD_Dot(25,7);
	GLCD_Dot(25,8);
	GLCD_Dot(25,11);
	GLCD_Dot(25,12);
	GLCD_Dot(25,34);
	GLCD_Dot(25,35);
	GLCD_Dot(25,39);
	GLCD_Dot(25,40);
	
	GLCD_Dot(24,6);
	GLCD_Dot(24,7);
	GLCD_Dot(24,8);
	GLCD_Dot(24,39);
	GLCD_Dot(24,40);
	GLCD_Dot(24,41);
	
	for(i=5;i<43;i++)
	{
		GLCD_Dot(23,i);
	}
	for(i=4;i<44;i++)
	{
		GLCD_Dot(22,i);
	}
	GLCD_Dot(21,4);
	GLCD_Dot(21,43);
	
	GLCD_Dot(20,4);
	GLCD_Dot(20,15);
	GLCD_Dot(20,18);
	GLCD_Dot(20,20);
	GLCD_Dot(20,21);
	GLCD_Dot(20,22);
	GLCD_Dot(20,23);
	GLCD_Dot(20,25);
	GLCD_Dot(20,27);
	GLCD_Dot(20,29);
	GLCD_Dot(20,31);
	GLCD_Dot(20,32);
	GLCD_Dot(20,33);
	GLCD_Dot(20,34);
	GLCD_Dot(20,43);
	
	GLCD_Dot(19,4);
	GLCD_Dot(19,15);
	GLCD_Dot(19,18);
	GLCD_Dot(19,20);
	GLCD_Dot(19,23);
	GLCD_Dot(19,25);
	GLCD_Dot(19,27);
	GLCD_Dot(19,29);
	GLCD_Dot(19,31);
	GLCD_Dot(19,43);
	
	GLCD_Dot(18,4);
	GLCD_Dot(18,15);
	GLCD_Dot(18,16);
	GLCD_Dot(18,17);
	GLCD_Dot(18,18);
	GLCD_Dot(18,20);
	GLCD_Dot(18,23);
	GLCD_Dot(18,25);
	GLCD_Dot(18,27);
	GLCD_Dot(18,29);
	GLCD_Dot(18,31);
	GLCD_Dot(18,32);
	GLCD_Dot(18,33);
	GLCD_Dot(18,34);
	GLCD_Dot(18,43);
	
	GLCD_Dot(17,4);
	GLCD_Dot(17,15);
	GLCD_Dot(17,18);
	GLCD_Dot(17,20);
	GLCD_Dot(17,23);
	GLCD_Dot(17,25);
	GLCD_Dot(17,26);
	GLCD_Dot(17,27);
	GLCD_Dot(17,28);
	GLCD_Dot(17,29);
	GLCD_Dot(17,31);
	GLCD_Dot(17,43);
	
	GLCD_Dot(16,4);
	GLCD_Dot(16,15);
	GLCD_Dot(16,18);
	GLCD_Dot(16,20);
	GLCD_Dot(16,21);
	GLCD_Dot(16,22);
	GLCD_Dot(16,23);
	GLCD_Dot(16,25);
	GLCD_Dot(16,26);
	GLCD_Dot(16,28);
	GLCD_Dot(16,29);
	GLCD_Dot(16,31);
	GLCD_Dot(16,32);
	GLCD_Dot(16,33);
	GLCD_Dot(16,34);
	GLCD_Dot(16,43);
	
	GLCD_Dot(15,4);
	GLCD_Dot(15,43);
	
	for(i=4;i<44;i++)
	{
		GLCD_Dot(14,i);
	}
	
	GLCD_Dot(13,28);
	GLCD_Dot(13,29);
	GLCD_Dot(13,37);
	GLCD_Dot(13,38);
	
	GLCD_Dot(12,29);
	GLCD_Dot(12,37);
	
	GLCD_Dot(11,29);
	GLCD_Dot(11,37);
	
	for(i=29; i<38;i++)
	{
		GLCD_Dot(10,i);
	}
	GLCD_Dot(9,29);
	GLCD_Dot(9,37);
	for(i=29; i<38;i++)
	{
		GLCD_Dot(8,i);
	}
	
}

void setplayer(void)				//플레이어 도트
{
	GLCD_Dot(63,50);
	GLCD_Dot(63,51);
	GLCD_Dot(63,55);
	GLCD_Dot(63,56);
	GLCD_Dot(63,78);
	GLCD_Dot(63,80);
	GLCD_Dot(63,82);
	GLCD_Dot(63,86);
	GLCD_Dot(63,87);
	GLCD_Dot(62,50);
	GLCD_Dot(62,51);
	GLCD_Dot(62,56);
	GLCD_Dot(62,57);
	GLCD_Dot(62,79);
	GLCD_Dot(62,80);
	GLCD_Dot(62,82);
	GLCD_Dot(62,83);
	GLCD_Dot(62,85);
	GLCD_Dot(62,86);
	GLCD_Dot(61,50);
	GLCD_Dot(61,51);
	GLCD_Dot(61,52);
	GLCD_Dot(61,57);
	GLCD_Dot(61,58);
	GLCD_Dot(61,79);
	GLCD_Dot(61,80);
	GLCD_Dot(61,81);
	GLCD_Dot(61,82);
	GLCD_Dot(61,83);
	GLCD_Dot(61,85);
	GLCD_Dot(60,51);
	GLCD_Dot(60,52);
	GLCD_Dot(60,58);
	GLCD_Dot(60,78);
	GLCD_Dot(60,79);
	GLCD_Dot(60,80);
	GLCD_Dot(60,81);
	GLCD_Dot(60,82);
	GLCD_Dot(60,83);
	GLCD_Dot(60,84);
	GLCD_Dot(60,85);
	GLCD_Dot(59,51);
	GLCD_Dot(59,52);
	GLCD_Dot(59,53);
	GLCD_Dot(59,54);
	GLCD_Dot(59,58);
	GLCD_Dot(59,78);
	GLCD_Dot(59,80);
	GLCD_Dot(59,81);
	GLCD_Dot(59,82);
	GLCD_Dot(59,84);
	GLCD_Dot(58,52);
	GLCD_Dot(58,53);
	GLCD_Dot(58,54);
	GLCD_Dot(58,55);
	GLCD_Dot(58,56);
	GLCD_Dot(58,57);
	GLCD_Dot(58,58);
	GLCD_Dot(58,78);
	GLCD_Dot(58,79);
	GLCD_Dot(58,80);
	GLCD_Dot(58,82);
	GLCD_Dot(58,83);
	GLCD_Dot(58,84);
	GLCD_Dot(57,53);
	GLCD_Dot(57,54);
	GLCD_Dot(57,55);
	GLCD_Dot(57,56);
	GLCD_Dot(57,57);
	GLCD_Dot(57,78);
	GLCD_Dot(57,80);
	GLCD_Dot(57,82);
	GLCD_Dot(57,84);
	GLCD_Dot(56,78);
	GLCD_Dot(56,79);
	GLCD_Dot(56,80);
	GLCD_Dot(56,82);
	GLCD_Dot(56,83);
	GLCD_Dot(56,84);
	GLCD_Dot(55,79);
	GLCD_Dot(55,80);
	GLCD_Dot(55,82);
	GLCD_Dot(55,83);
	GLCD_Dot(54,79);
	GLCD_Dot(54,80);
	GLCD_Dot(54,82);
	GLCD_Dot(54,83);
	GLCD_Dot(53,79);
	GLCD_Dot(53,80);
	GLCD_Dot(53,82);
	GLCD_Dot(53,83);
	GLCD_Dot(52,79);
	GLCD_Dot(52,80);
	GLCD_Dot(52,82);
	GLCD_Dot(52,83);
	GLCD_Dot(51,79);
	GLCD_Dot(51,80);
	GLCD_Dot(51,81);
	GLCD_Dot(51,82);
	GLCD_Dot(51,83);
	GLCD_Dot(50,81);
	
}