#include <stdio.h>
#include <stdlib.h>

extern void imprimirasm(float n);
extern void MULTIPLICARPORMENOS1(float n);/*le cambia el signo a lo que 
le pases por parametro y lo guarda en "float_mb"*/
extern void MULTIPLICARPORSIMISMO(float n);
extern float float_b;
extern float float_mb;
extern float bALcuadrado;


int main (){
float_b=10.0;

imprimirasm(float_b);
//MULTIPLICARPORMENOS1(float_b);

//imprimirasm(float_mb);
MULTIPLICARPORSIMISMO(float_b);
imprimirasm(bALcuadrado);


/*
printf("ingrese el valor a");
scanf("\n %f" ,&a);
printf("ingrese el valor b");
scanf("\n %f" ,&b);
printf("ingrese el valor c");
scanf("\n %f" ,&c);

imprimirasm(b);
//imprimirasm(c);
//imprimirasm(a);

MULTIPLICARPORMENOS1(b,menosB);
imprimirasm(menosB);
*/

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


