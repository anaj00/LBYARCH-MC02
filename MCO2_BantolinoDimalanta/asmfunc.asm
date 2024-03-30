; Bantolino, Jana Marie; Dimalanta, Jason Erwin Clyde | S17
; MC02

; Write a kernel that performs a dot product between vector A and B, and place the result in sdot

; Input: Scalar var n (int) contains the length of the vector. 
;        A and B are both single-precision float
;        Scalar sdot is a single precision float

; Output: Store result in memory loc sdot. Display the result for all version of the kernal

%include "io64.inc"
    
section .data
msg_1       db "Dot product (sdot): %.2f",10,0

section .text
extern printf
global getDotProd
getDotProd:
    movsd xmm1, qword [rsi]
    movsd xmm2, qword [rdi]
    mulsd xmm1, xmm2
    addsd xmm0, xmm1
    add rsi, 8
    add rdi, 8
    loop getDotProd
    
    
    movsd qword [sdot], xmm0
    xor rcx, rcx
    xor rdx, rdx
    
    movsd xmm0, [sdot]
    ret