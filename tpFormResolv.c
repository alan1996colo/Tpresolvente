#include <stdio.h>
#include <stdlib.h>

extern void imprimirasm(float n);
extern float CAMBIARSIGNO(float n);/*le cambia el signo a lo que 
le pases por parametro y te lo retorna */
extern float POTENCIAL2(float n);/*multiplica lo pasado por parametro
por si mismo y lo retorna*/
extern float MULTIPLY(float A,float C);/*multiplica los valores pasados por parametro
y los retorna */
extern float float_b;
extern float float_mb;
extern float bALcuadrado;
extern float ac4;
extern float float_a;
extern float float_c;


int main (){
float_a=2.0;
float_b=1.5;
float_c=3.0;
//POTENCIAL2(float_b);
//float_a=CAMBIARSIGNO2(float_a);
imprimirasm(float_a);
//imprimirasm(float_a);
float_a=POTENCIAL2(float_a);
//imprimirasm(float_mb);
//float_b=MULTIPLY(float_a,float_c);
//MULTIPLY(ac4,4.0);
imprimirasm(float_a);


//MULTIPLICARPORMENOS1(float_b);

//imprimirasm(float_mb);
//MULTIPLICARPORSIMISMO(float_b);
//imprimirasm(bALcuadrado);


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


