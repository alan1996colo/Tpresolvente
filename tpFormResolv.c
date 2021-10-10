#include <stdio.h>
#include <stdlib.h>

extern void imprimirasm(float n);
extern float CAMBIARSIGNO(float n);/*le cambia el signo a lo que 
le pases por parametro y te lo retorna */
extern float POTENCIAL2(float n);/*multiplica lo pasado por parametro
por si mismo y lo retorna*/
extern float MULTIPLY(float A,float C);/*multiplica los valores pasados por parametro
y los retorna */
extern float SUMAR(float a, float b);/*suma los dos valores pasados por parametro y
 retorna el resultado*/
extern float RAIZ2(float a);/*hace raiz cuadrada de lo pasado por parametro y lo retorna*/
extern float DIVIDIR(float a,float b);/*divide a /b y lo retorna*/
/*extern float float_b;
extern float float_mb;
extern float bALcuadrado;
extern float ac4;
extern float float_a;
extern float float_c;
¿para que hacerlas global si puedo administrar memoria desde C?
*/

int main (){
float ac4;//tiene el valor -4ac
float bALcuadrado;
float mb;//menos b
float ramaPOS;
float ramaNEG;
float result_en_raiz;//tiene el resultado dentro de la raiz
float a=1;
float b=1;
float c=-2;
float x2;
float x1;

printf("ingrese el valor a");
scanf("\n %f" ,&a);
printf("ingrese el valor b");
scanf("\n %f" ,&b);
printf("ingrese el valor c");
scanf("\n %f" ,&c);


mb=CAMBIARSIGNO(b);
bALcuadrado=POTENCIAL2(b);
ac4=MULTIPLY(-4,(MULTIPLY(a,c)));
result_en_raiz=SUMAR(ac4,bALcuadrado);//check hasta aca va bien.
ramaPOS=RAIZ2(result_en_raiz);
ramaNEG=CAMBIARSIGNO(ramaPOS);
ramaPOS=SUMAR(ramaPOS,mb); //check RAMA POS ESTA BIEN
ramaNEG=SUMAR(ramaNEG,mb);
a=MULTIPLY(2,a);//hago lo de 2*A **Si muevo este multply me altera todo el programa**


printf("\n el valor de 2*a es");
printf("%f \n",a);
printf("\n el valor de x1 es");
x2=DIVIDIR(ramaNEG,a);//Hay un problema en el orden en el que se disponen estas instrucciones
x1=DIVIDIR(ramaPOS,a);//si se ponen cerca de la linea 53 al parecer no funcionan adecuadamente.
imprimirasm(x1);
printf("\n el valor de x2 es");
imprimirasm(x2);
//printf("\n..");

/* //pasos a seguir:
float divisor= multiplicar2(a);
float x1=ramaPOS/divisor
float x2= ramaNEG/divisor
*/
	return 0;

}


