section .text
    global _ft_strlen

_ft_strlen:
    xor     rax, rax
    mov     rsi, rdi 

.align_check:
    test    rsi, 7
    jz      .block_loop

.byte_loop:
    movzx   rcx, byte [rsi]
    test    rcx, rcx
    jz      .done
    inc     rsi
    inc     rax
    test    rsi, 7
    jnz     .byte_loop

.block_loop:
    mov     rdx, [rsi]
    test    rdx, rdx
    jz      .found_in_block

    lea     rcx, [rsi]
    xor     r8, r8

.check_block:
    movzx   r9, byte [rcx + r8]
    test    r9, r9
    jz      .found_in_block
    inc     r8
    cmp     r8, 8
    jne     .check_block

    add     rsi, 8
    add     rax, 8
    jmp     .block_loop

.found_in_block:
    add     rax, r8

.done:
    ret
