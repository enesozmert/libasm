extern      ___error	; int ___error(int errnum, const char *msg);
section     .text
global      _ft_write

_ft_write:
    mov rax, 0x02000004 ; SYS_write | also 1 = SYS_write
    syscall             ; ; int write(int fd, const void *buf, size_t count);
    jc _ft_error        ; if carry flag is set, jump to error
    ret

_ft_error:
    push rax
    call ___error
    pop rdx
    mov [rax], rdx
    mov rax, -1
    ret