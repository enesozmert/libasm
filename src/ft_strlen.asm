section .text
global _ft_strlen

_ft_strlen:
    xor     rax, rax
.loop:
    cmp     byte [rdi, rax], 0
    je      .done
    inc     rax
    jmp     .loop
.done:
    ret