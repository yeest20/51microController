#include "Delay.h"
sfr P0 = 0x80;
sfr P2 = 0xA0;
sbit P22 = P2^2;
sbit P23 = P2^3;
sbit P24 = P2^4;

unsigned char NixieTable[10] = {0X3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void NixieTube(unsigned char Location, unsigned char Number){
	switch(Location){
		case 1:P22 = 0, P23 = 0, P24 = 0;break;
		case 2:P22 = 1, P23 = 0, P24 = 0;break;
		case 3:P22 = 0, P23 = 1, P24 = 0;break;
		case 4:P22 = 1, P23 = 1, P24 = 0;break;
		case 5:P22 = 0, P23 = 0, P24 = 1;break;
		case 6:P22 = 1, P23 = 0, P24 = 1;break;
		case 7:P22 = 0, P23 = 1, P24 = 1;break;
		case 8:P22 = 1, P23 = 1, P24 = 1;break;
	}
	P0 = NixieTable[Number];
}
void clearTube(){
		Delay(1);
		P0 = 0x00;
}