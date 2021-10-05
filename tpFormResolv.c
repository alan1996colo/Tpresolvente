#include <stdio.h>
#include <stdlib.h>

extern void CMAIN(float n);

int main (){
	
float a;
float b;
float c;	
printf("ingrese el valor a");
scanf("\n %f" ,&a);
printf("ingrese el valor b");
scanf("\n %f" ,&b);
printf("ingrese el valor c");
scanf("\n %f" ,&c);

CMAIN(a);

/* //pasos a seguir:
float menosb=MULTIPLICARPORMENOS1(b);//guardamos -b en la variable.
float bALcuadrado= MULTIPLICARPORSIMISMO(b);
float 4ac= MULTIPLY(A,C)*4.0;
4ac=MULTIPLICARPORMENOS1(4ac);
float resultadoDentroRaiz=SUMAR(4ac,bALcuadrado);

float ramaPOS=elevar05(resultadoDentroRaiz);

float ramaNEG=MULTIPLICARPORMENOS1(ramaPOS);

ramaPOS= ramaPOS + B;
ramaNEG= ramaNEG +B;

float divisor= multiplicar2(a);

float x1=ramaPOS/divisor
float x2= ramaNEG/divisor












*/
	return 0;




}


