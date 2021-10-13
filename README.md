#      **Trabajo Practico de Formula resolvente y producto escalar**
***Para ejecutar el programa siga los siguientes pasos***




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

***Al principio habia creado variables globales en asm, de las cuales podia acceder C,entonces las funciones en lugar de retornar floats, guardaban el resultado en esas variables y no retornaban nada. Me parecio que se hacia poco legible el codigo de esa forma, y lo implemente de manera tal que las funciones retornen el flotante, en lugar de guardarlos.***

Una complicacion por un detalle que tuve al principio fue que sin querer cambie la letra q por d al guardar result(cuando todavia guardaba en variables) y me costo que me daba cualquier numero despues.(qword[result] / dword[result]) eso modificaba el tamaño.

Otra complicacion que tuve fue que no inicialice la fpu `finit` entonces quedaban algunos valores en el stack, de los usos anteriores, de esto me di cuenta porque al hacer la funcion productoescalar, le agregue al main un while de manera que se pudiera usar una y otra vez, pero despues del primer uso, los siguientes resultados arrojaban -nan. Lo primero que pense fue que podria ser el orden de la instruccion `FMUL` o que habia otra instruccion para negativos, pero era imposible porque en el calculo de la resolvente funcionaba adecuadamente, entonces vincule esto con el problema de "orden en el main", y pense que algun registro podria estarse quedando con un dato basura, y busque la instruccion para limpiar en realidad, pero eso no me funciono, y probe con `finit` y si dio resultado. Entonces aplique `finit` al resto de funciones.,

#    **implementacion del producto escalar**

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


![Esta es una imagen](https://scontent.faep8-2.fna.fbcdn.net/v/t1.6435-9/240565301_10217560587120721_4078358438168620390_n.jpg?_nc_cat=102&_nc_rgb565=1&ccb=1-5&_nc_sid=730e14&_nc_ohc=JsqZS4aBSBkAX_LVGLZ&_nc_ht=scontent.faep8-2.fna&oh=b9f5315eaa3f84b1ec0a46ee96f504cb&oe=618BCFE7)

