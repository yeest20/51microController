sfr P2 = 0xA0;
sfr P3 = 0XB0;
sbit LED1 = P2^0;
sbit BUTTON1 = P3^1;
sbit BUTTON2 = P3^0;
void Delay(unsigned int xms)		//@12.000MHz
{
	

	unsigned char i, j;
	while(xms--){
	i = 2;
	j = 239;
	
		do
		{
			while (--j);
		} while (--i);
	}
}



unsigned char LEDNum = 0xFF;

void main(){
	while(1){
		if(BUTTON2 == 0) {
			Delay(20); 
			while(BUTTON2 == 0);
			Delay(20); 
			if(LEDNum == 0xFF){ 
				LEDNum = 0xFE;
				P2 = LEDNum;
			}
			else if(P2 != 0x7F){
				LEDNum = ~LEDNum;
				LEDNum = LEDNum << 1;
				LEDNum = ~LEDNum;
				P2 = LEDNum;
			}else{
				LEDNum = 0xFF;
				P2 = LEDNum;
			}
		}
		
		if(BUTTON1 == 0) {
			Delay(20); 
			while(BUTTON1 == 0);
			Delay(20); 
			if(LEDNum == 0xFF){ 
				LEDNum = 0x7F;
				P2 = LEDNum;
			}else if(LEDNum != 0xFE){
				LEDNum = ~LEDNum;
				LEDNum = LEDNum >> 1;
				LEDNum = ~LEDNum;
				P2 = LEDNum;
			}else{
				LEDNum = 0xFF;
				P2 = LEDNum;
			}
		}
	}
	return ;
}