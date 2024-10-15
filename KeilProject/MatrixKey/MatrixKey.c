#include <REGX52.H>
#include "Delay.h"


unsigned char MatrixKey(){
	unsigned char keyNumber = 0;
	P1 = 0xFF;
	P1_3 = 0;	
	if(P1_7 == 0) {Delay(20);while(P1_7 == 0); Delay(20);return keyNumber = 1;}
	if(P1_6 == 0) {Delay(20);while(P1_6 == 0); Delay(20);return keyNumber = 5;}
	if(P1_5 == 0) {Delay(20);while(P1_5 == 0); Delay(20);return keyNumber = 9;}
	if(P1_4 == 0) {Delay(20);while(P1_4 == 0); Delay(20);return keyNumber = 13;}
	P1_2 = 0;	
	if(P1_7 == 0) {Delay(20);while(P1_7 == 0); Delay(20);return keyNumber = 2;}
	if(P1_6 == 0) {Delay(20);while(P1_6 == 0); Delay(20);return keyNumber = 6;}
	if(P1_5 == 0) {Delay(20);while(P1_5 == 0); Delay(20);return keyNumber = 10;}
	if(P1_4 == 0) {Delay(20);while(P1_4 == 0); Delay(20);return keyNumber = 14;}
	P1_1 = 0;	
	if(P1_7 == 0) {Delay(20);while(P1_7 == 0); Delay(20);return keyNumber = 3;}
	if(P1_6 == 0) {Delay(20);while(P1_6 == 0); Delay(20);return keyNumber = 7;}
	if(P1_5 == 0) {Delay(20);while(P1_5 == 0); Delay(20);return keyNumber = 11;}
	if(P1_4 == 0) {Delay(20);while(P1_4 == 0); Delay(20);return keyNumber = 15;}
	P1_0 = 0;	
	if(P1_7 == 0) {Delay(20);while(P1_7 == 0); Delay(20);return keyNumber = 4;}
	if(P1_6 == 0) {Delay(20);while(P1_6 == 0); Delay(20);return keyNumber = 8;}
	if(P1_5 == 0) {Delay(20);while(P1_5 == 0); Delay(20);return keyNumber = 12;}
	if(P1_4 == 0) {Delay(20);while(P1_4 == 0); Delay(20);return keyNumber = 16;}
	return keyNumber;
}