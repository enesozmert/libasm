section .text
global _ft_strcpy

_ft_strcpy:
    mov     rax, rdi
.loop:
    mov     dl, [rsi]
    mov     [rdi], dl
    inc     rsi
    inc     rdi
    test    dl, dl
    jne     .loop
    ret