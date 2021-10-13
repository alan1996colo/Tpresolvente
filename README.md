#      **Trabajo Practico de Formula resolvente y producto escalar**
***Para ejecutar el programa siga los siguientes pasos***
1) Descargar los archivos: Presione en code, y luego en download zip.
![Descargar el archivo ](https://scontent.faep8-2.fna.fbcdn.net/v/t1.6435-9/245489018_10217752618121376_390424355651185012_n.jpg?_nc_cat=107&_nc_rgb565=1&ccb=1-5&_nc_sid=730e14&_nc_ohc=C_RNsXrwcJIAX9L9328&_nc_ht=scontent.faep8-2.fna&oh=d5f4cd87a31e02e0eda4901415f9b068&oe=618D7C7B)
2)Vaya a su carpeta de descargas, o donde haya descargado el archivo y extraiga el archivo (puede extraer alli o donde guste) se creara la carpeta Tpresolvente-master
![Extraer Archivo](https://scontent.faep8-2.fna.fbcdn.net/v/t1.6435-9/245387435_10217752618521386_7619106787302154022_n.jpg?_nc_cat=108&_nc_rgb565=1&ccb=1-5&_nc_sid=730e14&_nc_ohc=5iikS8qz4HoAX-1RtPO&_nc_ht=scontent.faep8-2.fna&oh=7408a48c2f160f8f9981f76de807d2bb&oe=618D1B59)

3)Abra la carpeta >Tpresolvente-master y dentro de ella abra la terminal(puede hacerlo haciendo segundo click o con ctrl+alt+t)
![Abrir Terminal](https://scontent.faep8-2.fna.fbcdn.net/v/t1.6435-9/245542815_10217752618201378_4105937340646264437_n.jpg?_nc_cat=102&_nc_rgb565=1&ccb=1-5&_nc_sid=730e14&_nc_ohc=16C3-Or-3HcAX9EuAjo&_nc_oc=AQlad20BkTh-H63IvUMN2rwzZbt6wODvVa2TCgoPY6vWMJULYYTgauRMHFL5QZ8tK8M&_nc_ht=scontent.faep8-2.fna&oh=8df3ef73f8476ee71c14fc2a0de342e8&oe=618B342E)
Asegurese de estar posicionado sobre >Tpresolvente-master.

4)Ejecute el script bash,en la terminal introduzca el siguiente comando ./ejecutarPrograma.sh

![ejecutar comando](https://scontent.faep8-1.fna.fbcdn.net/v/t1.6435-9/245402449_10217752617561362_7429618484117687242_n.jpg?_nc_cat=105&_nc_rgb565=1&ccb=1-5&_nc_sid=730e14&_nc_ohc=cT2YtXy-UekAX_awXjJ&_nc_ht=scontent.faep8-1.fna&oh=b667d9341ef9bd5f0e51531f4c1ba5e7&oe=618DEDA1)
5)Presione Enter y siga las instrucciones
![disfrutar programa](https://scontent.faep8-1.fna.fbcdn.net/v/t1.6435-9/245368234_10217752617481360_7405541865966547005_n.jpg?_nc_cat=111&_nc_rgb565=1&ccb=1-5&_nc_sid=730e14&_nc_ohc=8urt8LeCXYgAX9oiECz&_nc_ht=scontent.faep8-1.fna&oh=a837ae1aa4eb2d6717539459f1ef775c&oe=618E1DC0)
Disfrute del programa. 
![disfrutar programa](https://scontent.faep8-2.fna.fbcdn.net/v/t1.6435-9/245502115_10217752617401358_2545784027021193995_n.jpg?_nc_cat=109&_nc_rgb565=1&ccb=1-5&_nc_sid=730e14&_nc_ohc=4-wf54rFHuEAX_I3pjv&_nc_ht=scontent.faep8-2.fna&oh=dc0cae000fa28c659d518551c3fa2712&oe=618CD89A)

6)Para salir ingrese -1 y enter.
![salir del programa](https://scontent.faep8-2.fna.fbcdn.net/v/t1.6435-9/243517317_10217752616641339_8709624725321720363_n.jpg?_nc_cat=100&_nc_rgb565=1&ccb=1-5&_nc_sid=730e14&_nc_ohc=GGmUgYHrBJgAX-r8OT1&_nc_ht=scontent.faep8-2.fna&oh=57b603a18cd67251b5ceefc5be4f070d&oe=618C10B7)

#**Acerca del trabajo**

La idea del tp es implementar la formula resolvente en lenguaje ensamblador para la arquitectura IA32 y C .De manera que calcule las raices de una funcion cuadratica a traves de dicha formula.
Se debe tener en cuenta que las funciones para implementar las formula deben estar elaboradas en asm, y el programa puede recibir por parametro un valor de punto flotante.
Despues de ello se pedia elaborar un programa que calcule un producto escalar entre un vector y R, pero se puede considerar que el tamaño del vector(arreglo) ya se conoce.

# **Elaboracion de formula resolvente**

Para llevar a cabo este trabajo los pasos que fui llevando a cabo fueron:

- Primero, reducir la formula resolvente en funciones mas sencillas como por ejempo multiplicar,sumar,cambiarsigno.

- Cada funcion es golbal, es llamada desde asm hacia C ~~En un principio usaban variables globales en asm que tambien son llamadas por C y si es necesario modificadas.~~
- Hacer una funcion que muestre por pantalla el valor que estoy usando.

Comence por hacer la funcion `void imprimirasm(float n);` para ir viendo como cambia el valor de mis variables, para llevar a cabo esta simple funcion necesite una consulta con el profe ariel, acerca de como pasarle el parametro. Lo cual me mostro que el pasaje se llevaba a cabo manejando la pila desde esa misma funcion en asm, con los registros esp y ebp cargando los punteros al FPU.Despues de contemplada esa duda, teniendo  ese ejemplo como base comence a desarrollar las demas funciones
empezando por ` float CAMBIARSIGNO(float n);` para la cual me apoye con el set de instrucciones de la FPU que se encuentra en 
https://es.m.wikipedia.org/wiki/Anexo:Instrucciones_x86
Y asi encontre la instruccion fchs



`

`global CAMBIARSIGNO`


`CAMBIARSIGNO:`

    ;enter
    
    push ebp ;guardo el puntero base de la pila
    
    mov ebp, esp ;apunto la base de la pila al actual.
    
    ;
    FINIT
   
    fld dword[ebp + 8] ;carga el punto flotante
    fchs  ;le cambio el signo
    ;leave
    mov esp, ebp
    pop ebp ;
     ret`
De esta  forma debi entender que los flotantes se manejan con el st0 de la pila...

El primer inconveniente que tuve fue la multiplicacion y el pasaje de parametros, ya que para la multiplicacion de numeros flotantes se debe usar el stack la FPU, y no los registros convencionales, y yo estaba meta intentar con edx,ebx , eax, etc.
Se me complico sobre todo porque encontraba la instruccion, pero no la sintaxis, y yo lo estaba usando sobre esos registros, en lugar de st0,st1.
Otra complicacion que tuve fue que el sasm que tengo instalado no compila mis fuentes y el gdb no me abre los archivos por alguna falta de libreria amd-64, por lo tanto utilice plenamente el Visual Studio. Senti que si pudiera visualizar los registros me hubiera dado cuenta mas rapido de mis errores...
Un error comun que tuve fue el clasico -nan , debido a que 
- no estoy apuntando al st adecuado.
- no estoy apuntando a un contenido sino a una direccion que contenie otra direccion(caso vectores)
- hago una operacion aritmetica entre direccion y contenido o similar.


**implementacion de multiplicar**

![multiply](https://scontent.faep8-2.fna.fbcdn.net/v/t1.6435-9/245229928_10217752746764592_5159126047902093443_n.jpg?_nc_cat=102&_nc_rgb565=1&ccb=1-5&_nc_sid=730e14&_nc_ohc=2olaS-cUzqwAX9-WX8F&_nc_ht=scontent.faep8-2.fna&oh=839f15a48eaf3bedd399d60c31b66cb8&oe=618C163E)

***Al principio habia creado variables globales en asm, de las cuales podia acceder C,entonces las funciones en lugar de retornar floats, guardaban el resultado en esas variables y no retornaban nada. Me parecio que se hacia poco legible el codigo de esa forma, y lo implemente de manera tal que las funciones retornen el flotante, en lugar de guardarlos.***

**implementacion de raiz**

![raiz2](https://scontent.faep8-2.fna.fbcdn.net/v/t1.6435-9/245391903_10217752761204953_6092832315703465886_n.jpg?_nc_cat=104&_nc_rgb565=1&ccb=1-5&_nc_sid=730e14&_nc_ohc=vjeqpzM18RAAX8hN5Tl&_nc_ht=scontent.faep8-2.fna&oh=81c6c2cc9f8f558de479f7120209966d&oe=618B51DD)
_para implementar la funcion raiz,estaba pensando en hacer potencia 0.5, pero vi que el set tenia una instruccion especial asi que utilice la instruccion `fsqrt`_


_En el resto de funciones se repiten los mismo pasos vistos, pero con su instruccion especia `FADD`, `FDIV`,etc.__

Una complicacion por un detalle que tuve al principio fue que sin querer cambie la letra q por d al guardar result(cuando todavia guardaba en variables) y me costo que me daba cualquier numero despues.(qword[result] / dword[result]) eso modificaba el tamaño.

Otra complicacion que tuve fue que no inicialice la fpu `finit` entonces quedaban algunos valores en el stack, de los usos anteriores, de esto me di cuenta porque al hacer la funcion productoescalar, le agregue al main un while de manera que se pudiera usar una y otra vez, pero despues del primer uso, los siguientes resultados arrojaban -nan. Lo primero que pense fue que podria ser el orden de la instruccion `FMUL` o que habia otra instruccion para negativos, pero era imposible porque en el calculo de la resolvente funcionaba adecuadamente, entonces vincule esto con el problema de "orden en el main", y pense que algun registro podria estarse quedando con un dato basura, y busque la instruccion para limpiar en realidad, pero eso no me funciono, y probe con `finit` y si dio resultado. Entonces aplique `finit` al resto de funciones.,

#    **implementacion del producto escalar**
![productoEscalar](https://scontent.faep8-1.fna.fbcdn.net/v/t1.6435-9/245343544_10217752725804068_7152793907575175136_n.jpg?_nc_cat=110&_nc_rgb565=1&ccb=1-5&_nc_sid=730e14&_nc_ohc=yrb6gfYp2m0AX9QOXM2&_nc_ht=scontent.faep8-1.fna&oh=589974095354f17624fe54642483b8bc&oe=618B96E6)

Para desarrollar el producto escalar tuve un stall en mi pipeline (jeje), porque no lei correctamente la consigna, y me habia hecho idea de que habia que hacerlo en C usando las funciones ya desarrolladas. Ya lo estaba terminando cuando se me ocurrio repasar la consigna para ver si me quedaba algo mas por hacer, entonces entendi que pedia **UN SOLO VECTOR** y que se desarrolle en asm ia32 (ya lo habia hecho en C para que el usuario decida cantidad de vectores y coordenadas ja)
Entonces perdi todo ese tiempo, y comence a hacerlo en asm. Entiendo que producto escalar es la suma del producto entre las coordenadas de dos vectores *V1=(a,b,c) , v2=(a2,b2,c2), producto v1*v2= (a1*a2+b1*b2+c1*c2)*
Por lo tanto al ver el enunciado que pedia entre un numero R y un vector, se me hizo raro. Pero asumo que pide lo siguiente:
**v*r=(ar+br+cr)**
Teniendo en cuenta esta premisa, elabore mi funcion `float PRODUCTOESCALAR(float r, float vectores[])` la cual no fue facil de hacer, dado que lo primero es entender como funciona un vector en C.
Despues de investigar como funciona un vector en C, el pasaje de parametros sobre todo ~~(compile y ejecute un monton de maneras distintas de escribir vectores,&vectores[],vectores[cant],*vectores[],*parser*  hasta que di con la correcta jaja)

Le pase el parametro de asm, y me encontre con que? si con el clasico -nan.
lo primero que pense fue, no estoy accediendo a la posicion correcta de memoria,intente pasar el contenido entre registros de la fpu y no pude.
Al otro dia, se me ocurrio que la direccion de memoria, apunta a otra direccion de memoria,¿entonces como visualizo?
registros convencionales fue la respuesta. Cargue un registro de 32bits con el conenido(es decir otra direccion) y hice que otro registro apunte a ese contenido y taran, funciona, ahi esta el primer elemeto de mi arreglo, el resto fue solo sumar +4 y fin del problema. 
Una vez que ya pude visualizar mi numero del vector, lo que hice fue usar mis habilidades matematicas para cambiar esta expresion: **v*r=(ar+br+cr)** por esta otra **v*r=r(a+b+c)** de esta manera en lugar de hacer muchas multiplicaciones y sumas, solo hago una multiplicacion y 3 sumas ~~(mucho mejor) (algebra de boole un poroto)~~
Entonces use `FADD` para sumar los valores y finalmente `FMUL` para multiplicarlos con r.


Todo esto lo compile usando los comandos 
>nasm -f elf32 tpFormResolv.s -o tpFormResolv.o
>gcc -m32 -o prueba1 tpFormResolv.o tpFormResolv.c

para ejecutar
>./prueba1  

Fin del trabajo.
