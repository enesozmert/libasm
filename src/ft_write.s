extern __errno_location

section .text
global _ft_write

_ft_write:
    mov rax, 1
    syscall
    jc _ft_error
    ret

_ft_error:
    neg		rax	
    mov rdi, rax
    call qword [rel __errno_location wrt ..got]
    mov qword [rax], rdi
    mov rax, -1
    ret
