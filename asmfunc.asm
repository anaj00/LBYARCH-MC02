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

vec_A       dd 1.0, 2.0, 3.0, 4.0
vec_B       dd 2.0, 3.0, 4.0, 5.0
n           dd 4
sdot        dq 0.0

msg_1       db "Dot product (sdot): %f",10,0

section .text
extern printf
global main

main:
    mov rbp, rsp; for correct debugging
    
    sub rsp, 8*4 ; 2 because only 2 parameter
    
    movss xmm0, [zero]
    mov rax, vec_A 
    mov rbx, vec_B
    mov rcx, [n] ; counter (length)
    
    ; TODO: Dot product loop
getDotProd:
    movss xmm1, dword [rax] 
    movss xmm2, dword [rbx]
    mulss xmm1, xmm2        ; A[i] x B[i]
    addss xmm0, xmm1        ; sum
    add rax, 4              ; next float
    add rbx, 4              ; next float
    dec rcx                 ; - counter
    jnz getDotProd
    
    ; TODO: Store in sdot
    movss dword [sdot], xmm0
    
    ; TODO: Display sdot
    xor rcx, rcx ; clear for parameter use
    xor rdx, rdx
   
    mov rcx, msg_1
    mov rdx, [sdot]
    call printf
    
    add rsp, 8*4
    ret