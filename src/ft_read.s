extern __errno_location

section .text
global _ft_read

_ft_read:
    mov rax, 0
    syscall
    jc _ft_error
    ret

_ft_error:
    neg     rax
    mov     rdi, rax
    call    qword [rel __errno_location wrt ..got]
    mov     dword [rax], edi 
    mov     eax, -1
    ret
