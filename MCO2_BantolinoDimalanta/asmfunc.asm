; Bantolino, Jana Marie; Dimalanta, Jason Erwin Clyde | S17
; MC02

; Write a kernel that performs a dot product between vector A and B, and place the result in sdot

; Input: Scalar var n (int) contains the length of the vector. 
;        A and B are both single-precision float
;        Scalar sdot is a single precision float

; Output: Store result in memory loc sdot. Display the result for all version of the kernal

section .data
sdot   dq 34.0

section .text
bits 64
default rel
global getDotProductx64

getDotProductx64:
    push rsi
    push rdi

 
    mov rsi, r8           ; Pointer to vec_A in rsi
    mov rdi, r9           ; Pointer to vec_B in rdi
   
    
    xorpd xmm0, xmm0      ; Initialize accumulator to 0

dot_product_loop:
    movsd xmm1, [rsi]     ; Load value from vec_A
    mulsd xmm1, [rdi]     ; Multiply with value from vec_B
    addsd xmm0, xmm1      ; Add result to accumulator
    add rsi, 8            ; Move to next element in vec_A
    add rdi, 8            ; Move to next element in vec_B
    loop dot_product_loop ; Loop until rcx is 0

    ; Store constant value 34.0 into asm_dotProduct
    movsd [rdx], xmm0     ; Store result in asm_dotProduct

    pop rdi
    pop rsi
    ret