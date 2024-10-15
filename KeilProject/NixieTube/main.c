#include "Delay.h"
#include "NixieTube.h"

void main(){
	while(1){
		NixieTube(8, 1);
		Delay(500);
		NixieTube(7, 2);	
		Delay(500);
		NixieTube(6, 3);
		Delay(500);
		NixieTube(5, 4);
		Delay(500);
		NixieTube(4, 5);
		Delay(500);
		NixieTube(3, 6);
		Delay(500);
		NixieTube(2, 7);
		Delay(500);
		NixieTube(1, 8);
		Delay(500);
		while(1){
			NixieTube(8, 1);
			clearTube();
			NixieTube(7, 2);	
			clearTube();
			NixieTube(6, 3);
			clearTube();
			NixieTube(5, 4);
			clearTube();
			NixieTube(4, 5);	
			clearTube();
			NixieTube(3, 6);
			clearTube();
			NixieTube(2, 7);
			clearTube();
			NixieTube(1, 8);	
			clearTube();
		}
		
	}
}