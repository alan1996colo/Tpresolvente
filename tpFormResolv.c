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

extern float PRODUCTOESCALAR(float r,float vectores[]);
/*extern float float_b;
extern float float_mb;
extern float bALcuadrado;
extern float ac4;
extern float float_a;
extern float float_c;
¿para que hacerlas global si puedo administrar memoria desde C?
*/
void p(int cant,float vectores[]){
for(int j=0;j<cant;j++){
		printf("\n %f \n",vectores[j]);
	}return ;};
	//visualizamos el vector
	
	
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
int cantCordenadas=3;


//int cantVectores=2;
//nos damos cuenta que solo pedia UN solo vector
//printf("\n ingrese la cantidad de vectores que va emplear");
//scanf("%i",&cantVectores);
printf("\n ingrese la cantidad de coordenadas que va usar ");
scanf("%i",&cantCordenadas);
float vectores[cantCordenadas];
//float vectores [cantVectores][cantCordenadas];
//creamos la matriz
//for (int i=0;i<cantVectores;i++){
for(int j=0;j<cantCordenadas;j++){
	printf("\n ingrese el valor de la cordenada %i  :",j+1);
	//printf("  en el vector %i :",i+1);
	scanf("%f",&vectores[j]);
}

p(cantCordenadas,vectores); //vemos el vector

/*En matemáticas, el producto escalar,también conocido como producto interno o 
producto punto, es una operación algebraica que toma dos secuencias de números 
de igual dimensión (usualmente en la forma de vectores) y "retorna un único número".
*/
a=PRODUCTOESCALAR(2.0,vectores);
imprimirasm(a);

//a=p(2.3,vectores);



//Por lo tanto debe multiplicar cada coordenada * R 
//y retornar la suma de esos productos.
/* 
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


