; Bantolino, Jana Marie; Dimalanta, Jason Erwin Clyde | S17
; MC02

; Write a kernel that performs a dot product between vector A and B, and place the result in sdot

; Input: Scalar var n (int) contains the length of the vector. 
;        A and B are both single-precision float
;        Scalar sdot is a single precision float

; Output: Store result in memory loc sdot. Display the result for all version of the kernal

section .data
sdot   dq 0.0

section .text
bits 64
default rel
global getDotProduct

getDotProduct:
    lea rsi, [rcx]
    lea rdi, [rdx]
    xor rcx, rcx
    mov rcx, r8 ; counter (length)
    xorpd xmm0, xmm0
    
dotproduct_loop:
    movsd xmm1, [rsi]
    movsd xmm2, [rdi]
    mulsd xmm1, xmm2
    addsd xmm0, xmm1
    add rsi, 8
    add rdi, 8
    loop dotproduct_loop
    movsd [sdot], xmm0
    
 
    xor rcx, rcx
    xor rax, rax
    ret