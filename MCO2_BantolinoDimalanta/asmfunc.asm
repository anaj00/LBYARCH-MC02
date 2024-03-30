%include "io64.inc"
    
section .data
msg_1       db "Dot product (sdot): %.2f",10,0

section .text
bits 64
default rel

global getDotProduct
extern printf

getDotProduct:
    sub rsp, 8*5 ; caller
    mov rcx, msg1
    call printf
    add rsp, 8*5
    ret
    ret