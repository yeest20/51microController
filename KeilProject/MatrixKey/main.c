#include <REGX52.H>
#include "Delay.h"
#include "NixieTube.h"
#include "MatrixKey.h"

unsigned char keyNum, stayNum;
unsigned int Password;
void main(){
	while(1){
		keyNum = MatrixKey();
		if(keyNum){
			stayNum = keyNum;
			if(keyNum <= 10){
				Password = Password * 10 + keyNum % 10;
			}
			if(keyNum == 11){
				if(Password == 1028) {
					P2_7 = 0;
					while(1){
						NixieTube(2, 0);
						clearTube();
						NixieTube(1, 15);
						clearTube();
					}
				}
				else {
					P2_6 = 0, Password = 0;
					while(1){
						NixieTube(2, 14);
						clearTube();
						NixieTube(1, 14);
						clearTube();
					}
				}
			}
			if(keyNum == 12){
				Password = 0;
			}
			if(keyNum == 13){
				P2_7 = 1;
				P2_6 = 1;
				Password = 0;
			}
		}
		NixieTube(1, stayNum);
		
	}
}