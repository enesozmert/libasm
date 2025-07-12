extern __errno_location

section .text
global _ft_write

_ft_write:
    mov rax, 1          ; SYS_write (Linux için)
    syscall
    jc _ft_error        ; hata varsa _ft_error’a git
    ret

_ft_error:
    ; RIP-relative olarak __errno_location adresini al
    call qword [rel __errno_location wrt ..got]
    mov qword [rax], -1 ; errno = -1
    mov rax, -1         ; fonksiyon -1 döndürsün
    ret
