; Bantolino, Jana Marie; Dimalanta, Jason Erwin Clyde | S17
; MC02

; Write a kernel that performs a dot product between vector A and B, and place the result in sdot

; Input: Scalar var n (int) contains the length of the vector. 
;        A and B are both single-precision float
;        Scalar sdot is a single precision float

; Output: Store result in memory loc sdot. Display the result for all version of the kernal

%include "io64.inc"

section .bss
    zero resb 16
    
section .data

vec_A       dq 1.9, 2.0, 3.0, 4.0
vec_B       dq 2.0, 3.0, 4.0, 5.5
n           dq 4
sdot        dq 0.0

msg_1       db "Dot product (sdot): %.2f",10,0

section .text
extern printf
global main

main:
    mov rbp, rsp; for correct debugging
    
    sub rsp, 8*4 ; 2 because only 2 parameter
    
    lea rsi, [vec_A]
    lea rdi, [vec_B]
    mov rcx, [n] ; counter (length)
    
    xorpd xmm0, xmm0
    ; TODO: Dot product loop
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
    
    ;Print 
    lea rcx, [msg_1]
    mov rdx, [sdot]
    call printf
    add rsp, 8*4
    ret