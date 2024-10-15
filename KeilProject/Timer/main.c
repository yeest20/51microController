#define MULTINUM 9
#define RIGHT 1
#define LEFT 0
unsigned char direction = 1;

sfr P2 = 0xA0;
sfr P3 = 0xB0;
sbit KEY1 = P3^2;
sbit KEY2 = P3^3;
// 定时器寄存器
sfr TCON = 0x88;
sfr TMOD = 0x89;
sfr TL0  = 0x8A;
sfr TH0  = 0x8C;
unsigned char multi = MULTINUM;
sbit TF0 = TCON ^ 5;
sbit TR0 = TCON ^ 4;
// 中断寄存器
sfr IE = 0xA8;
sbit EA = IE^7;
sbit ET0 = IE^1;
sbit EX0 = IE^0;
sbit EX1 = IE^2;
sbit IE1 = TCON^3;
sbit IT1 = TCON^2;
sbit IE0 = TCON^1;
sbit IT0 = TCON^0;

void Timer0_Init(){
	// 定时寄存器配置
	TMOD &= 0xF0; 
	TMOD |= 0X01; //16位定时器, 不覆盖赋值方法
	TF0 = 0;
	TR0 = 1;
	TL0 = 0xAF;
	TH0 = 0x3C; // 50ms
	// 中断寄存器配置
	EA = 1;
	ET0 = 1;
}
void ExternalInterrupt0_Init(){

	EA = 1;
	EX0 = 1;
	IT0 = 1; //下降沿触发
	IE0 = 0;
}

void ExternalInterrupt1_Init(){
	EA = 1;
	EX1 = 1;
	IT1 = 1; //下降沿触发
	IE1 = 0;
}
void main(){
	P2 = 0xFE;
	Timer0_Init();
	ExternalInterrupt0_Init();
	ExternalInterrupt1_Init();
	while(1){

	}
	
}


void Timer0_Routine() interrupt 1{
	if(multi) {multi--;return;}
	if(direction == RIGHT){
		if(P2 == 0x7F)P2 = 0xFE;
		else{
			unsigned char tmp;
			tmp = ~P2;
			tmp = tmp << 1;
			P2 = ~tmp;
		}
	}
	if(direction == LEFT){
		if(P2 == 0xFE) P2 = 0x7F;
		else{
			unsigned char tmp;
			tmp = ~P2;
			tmp = tmp >> 1;
			P2 = ~tmp;
		}
	
	}
	TL0 = 0xAF;
	TH0 = 0x3C; // 50ms
	multi = MULTINUM;
	return;
}
	
		


void Int0_Routine()interrupt 0{
		direction = LEFT;
}
	
void Int1_Routine()interrupt 2{
		direction = RIGHT;
}

	


