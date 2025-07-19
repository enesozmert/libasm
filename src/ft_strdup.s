section .text
extern malloc
extern __errno_location
extern _ft_strlen
extern _ft_strcpy
global _ft_strdup

_ft_strdup:
    push rdi
    call _ft_strlen
    inc rax
    mov rdi, rax

    call malloc wrt ..plt
    test rax, rax
    jz _error
    pop rdi

    mov rsi, rdi
    mov rdi, rax
    call _ft_strcpy
    ret

_error:
	pop		rdi
	call	__errno_location wrt ..plt
	mov		rdx, 12
	mov		[rax], rdx
	mov		rax, 0
	ret
