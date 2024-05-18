section .text
global _ft_strcmp

_ft_strcmp:
    push rbp
    mov rbp, rsp
    mov rsi, rdi    ; rdi'deki s1'i rsi'ye kopyala
    mov rdx, rsi    ; rsi'deki s2'yi rdx'e kopyala

    .compare_loop:
        ; Eğer *s1 ve *s2 aynı değilse veya biri null-terminating karakterse çık
        cmp byte [rsi], 0
        je .strings_match
        cmp byte [rdx], 0
        je .strings_match

        ; *s1 ve *s2 karşılaştır
        mov al, [rsi]
        cmp al, [rdx]
        jne .strings_differ

        ; İlerleme sağla
        inc rsi
        inc rdx
        jmp .compare_loop
    
    .strings_match:
        ; Karakter dizileri eşit, sonucu 0 olarak ayarla ve çık
        xor eax, eax
        jmp .exit

    .strings_differ:
        ; Karakter dizileri farklı, sonucu karşılaştırma sonucuna göre ayarla ve çık
        mov eax, 1
        jl .exit
        mov eax, -1

    .exit:
        ; Çıkış yapıp parametreleri geri yükle
        pop rbp
        ret