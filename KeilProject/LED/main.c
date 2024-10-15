#include <INTRINS.H>

sfr P2 = 0xA0;
void Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms--){
		i = 2;
		j = 239;
		do
		{
			while(--j);
		}while(--i);
	}
}



void main(){
	while(1){
		P2 = 0xFE;
		Delay(100);
		P2 = 0xFD;
		Delay(100);
		P2 = 0xFB;
		Delay(100);
		P2 = 0xF7;
		Delay(100);
		P2 = 0xEF;
		Delay(100);
		P2 = 0xDF;
		Delay(100);
		P2 = 0xBF;
		Delay(100);
		P2 = 0x7F;
		Delay(100);
	}

}