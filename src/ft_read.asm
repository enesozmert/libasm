extern __errno_location

section .text
global _ft_read

_ft_read:
    mov rax, 0              ; SYS_read (Linux)
    syscall
    jc _ft_error            ; Hata varsa _ft_error’a git
    ret                     ; Başarılıysa dönüş (RAX = okunan byte sayısı)

_ft_error:
    neg     rax             ; RAX = -errno → errno’ya çevir (pozitif)
    mov     rdi, rax        ; errno (1. arg)
    call    qword [rel __errno_location wrt ..got]
    mov     dword [rax], edi ; errno = pozitif hata kodu
    mov     eax, -1         ; return -1
    ret