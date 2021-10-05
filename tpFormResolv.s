
extern printf

section .data
    format db "%f",10,0
    result dq 0.0
section .text
global CMAIN
CMAIN:
    mov ebp, esp
    ;enter
    push ebp
    mov ebp, esp
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
    ret