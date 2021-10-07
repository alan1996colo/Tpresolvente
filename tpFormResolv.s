
extern printf

section .data
    global format
    format:
     db "%f",10,0
    global float_b
    float_b:
     dd 0.0
    global float_mb
    float_mb:
    dd 0.0
    global bALcuadrado
    bALcuadrado:
    dd 0.0

result dq 0.0
    
section .text


global imprimirasm
imprimirasm:
;mov ebp, esp
    ;enter
    push ebp ;guardo el puntero base de la pila
    mov ebp, esp ;apunto la base de la pila al actual.
    ;------
    
    fld dword[ebp + 8] ;carga el punto flotante
    fst qword[result] ; store, lo guarda en la etiqueta result
    
    ;--- Muestro por pantalla
    push dword[result+4] ; +4
    
    push dword[result] ; +4
    push format  ; +4
    call printf ;llama a printf desde C 
    
    add esp,12  
    
    ;leave
    mov esp, ebp
    pop ebp ;restauro el ebp viejo porque en la linea 25 ya habia restaurado el esp +12
    ret

global MULTIPLICARPORMENOS1
MULTIPLICARPORMENOS1:
;enter
    push ebp ;guardo el puntero base de la pila
    mov ebp, esp ;apunto la base de la pila al actual.
    ;------
   
    fld dword[ebp + 8] ;carga el punto flotante
    fst qword[result]
    push dword[result] ;lo pongo  arriba en la pila
    fchs  ;le cambio el signo
    fst dword[float_mb] ;lo guardo en lo que seria la segunda variable
    add esp,4
   
    
 ;leave
   mov esp, ebp
   pop ebp ;
    ret
global MULTIPLICARPORSIMISMO
MULTIPLICARPORSIMISMO:
;enter
push ebp ;guardo el puntero base de la pila
mov ebp, esp ;apunto la base de la pila al actual.
;------
   
    fld dword[ebp + 8] ;carga el punto flotante
    
    fmul st0,st0
    
    fst qword[bALcuadrado]
    
    add esp,4
   
    
 ;leave
   mov esp, ebp
   pop ebp ;
   ret