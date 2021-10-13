#include <stdio.h>
#include <stdlib.h>

extern void imprimirasm(float n);
extern float CAMBIARSIGNO(float n);		 /*le cambia el signo a lo que 
le pases por parametro y te lo retorna */
extern float POTENCIAL2(float n);		 /*multiplica lo pasado por parametro
por si mismo y lo retorna*/
extern float MULTIPLY(float A, float C); /*multiplica los valores pasados por parametro
y los retorna */
extern float SUMAR(float a, float b);	 /*suma los dos valores pasados por parametro y
 retorna el resultado*/
extern float RAIZ2(float a);			 /*hace raiz cuadrada de lo pasado por parametro y lo retorna*/
extern float DIVIDIR(float a, float b);	 /*divide a /b y lo retorna*/

extern float PRODUCTOESCALAR(float r, float vectores[]); /*multiplica cada elemento del vector *R y los suma, y devuelve el resultado
solo funciona con exactamente 3 coordenadas*/
void p(int cant, float vectores[])//MUESTRA EL VECTOR
{
	for (int j = 0; j < cant; j++)
	{
		printf("\n %f \n", vectores[j]);
	}
	return;
};
int main()
{
	float ac4; //tiene el valor -4ac
	float bALcuadrado;
	float mb; //menos b
	float ramaPOS;
	float ramaNEG;
	float result_en_raiz; //tiene el resultado dentro de la raiz
	float a = 1;
	float b = 1;
	float c = -2;
	float x2;
	float x1;
	int cantCordenadas = 3;
	int elegirPRG = 0;
	while (elegirPRG >= 0)//corremos el programa mientras ingresemos un valor mayor igual a cero
	{
		printf("\n ingrese 1 para producto escalar o 2 para calcular resolvente: \n");
		printf("\n <0 finaliza. \n");
		scanf("%i", &elegirPRG);
		if (elegirPRG == 1)//entramos en el programa de producto escalar
		{
			float vectores[cantCordenadas];
			for (int j = 0; j < cantCordenadas; j++)//asignamos los valores al vector
			{
				printf("\n ingrese el valor de la cordenada %i  :", j + 1);
				scanf("%f", &vectores[j]);
			}

			p(cantCordenadas, vectores); //vemos el vector

/*TENEMOS EN CUENTA QUE En matemáticas, el producto escalar,también conocido como producto interno o 
producto punto, es una operación algebraica que toma dos secuencias de números 
de igual dimensión (usualmente en la forma de vectores) y "retorna un único número".
*/

			printf("\n ingrese el valor de R :");
			scanf("%f", &a);
			a = PRODUCTOESCALAR(a, vectores);
			printf("\n el producto escalar es:");
			imprimirasm(a);
			//Por lo tanto debe multiplicar cada coordenada * R
			//y retornar la suma de esos productos.

			//elegirPRG=-1;//finalizo el programa
		}
		if (elegirPRG == 2)//Entramos en el programa calcula resovente
		{
			printf("ingrese el valor a");//asignamos los valores
			scanf("\n %f", &a);
			printf("ingrese el valor b");
			scanf("\n %f", &b);
			printf("ingrese el valor c");
			scanf("\n %f", &c);
            //comienza la resolvente
			mb = CAMBIARSIGNO(b);
			bALcuadrado = POTENCIAL2(b);
			ac4 = MULTIPLY(-4, (MULTIPLY(a, c)));
			result_en_raiz = SUMAR(ac4, bALcuadrado); 
			ramaPOS = RAIZ2(result_en_raiz);
			ramaNEG = CAMBIARSIGNO(ramaPOS);
			ramaPOS = SUMAR(ramaPOS, mb); 
			ramaNEG = SUMAR(ramaNEG, mb);
			a = MULTIPLY(2, a); 
			x2 = DIVIDIR(ramaNEG, a); 
			x1 = DIVIDIR(ramaPOS, a); 
			if (x1>=0.0 || x1<=0.0){//condicionamos el retorno para que solo muestre numeros  Reales y no -nan
			    printf("\n el valor de x1 es : ");
			    imprimirasm(x1);
			    printf("\n el valor de x2 es : ");
			    imprimirasm(x2);
			}
		    else{
				printf("no pertenece a los Reales");
				}
		}
	}
	return 0; //fin del programa
}