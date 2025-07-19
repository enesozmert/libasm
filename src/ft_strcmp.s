section .text
    global _ft_strcmp

_ft_strcmp:
    push    rbx

.loop8:
    mov     rax, [rdi]
    mov     rbx, [rsi]

    xor     rcx, rcx
    cmp     rax, rbx
    jne     .find_diff

    mov     r8, 0x0101010101010101
    mov     r9, 0x8080808080808080
    mov     rdx, rax
    sub     rdx, r8
    not     rax
    and     rax, rdx
    and     rax, r9
    test    rax, rax
    jnz     .check_null

.find_diff:
.find_byte:
    mov     al, [rdi + rcx]
    mov     bl, [rsi + rcx]
    cmp     al, bl
    jne     .return_diff
    test    al, al
    je      .return_diff
    inc     rcx
    cmp     rcx, 8
    jne     .find_byte
    jmp     .loop8

.check_null:
    ; null byte bulunduktan sonra
    mov     al, [rdi + rcx]
    mov     bl, [rsi + rcx]
    cmp     al, bl
    jne     .return_diff
    test    al, al
    je      .return_equal
    inc     rcx
    jmp     .check_null

.return_diff:
    movzx   eax, al         ; s1 byte’ı
    movzx   ebx, bl         ; s2 byte’ı
    sub     eax, ebx        ; fark = s1[i] - s2[i]
    pop     rbx
    ret

.return_equal:
    xor     eax, eax        ; fark yok, eşit
    pop     rbx
    ret
