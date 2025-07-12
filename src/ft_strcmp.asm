section .text
    global _ft_strcmp

_ft_strcmp:
.loop:
    mov     al, [rdi]
    xor     ebx, ebx
    mov     bl, [rsi]
    cmp     al, bl
    jne     .diff
    test    al, al
    je      .equal
    inc     rdi
    inc     rsi
    jmp     .loop
.diff
    xor     eax, eax
    mov     al, [rdi]
    mov     eax, ebx 
    ret
.equal
    xor     eax, eax
    ret
