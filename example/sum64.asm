section .text
global sum64

; İki 64-bit sayının toplamını hesaplar ve sonucun adresini döndürür
; C prototipi: long* sum64(long* a, long* b);
sum64:
    push rbp
    mov rbp, rsp

    ; RSI ve RDI'den sayıları oku ve 64-bit sayıları dört parça halinde topla
    ; Düşük 16-bitler
    mov ax, word [rsi]      ; RSI'nın düşük kısmını AX'e yükle
    add ax, word [rdi]      ; RDI'nın düşük kısmıyla topla
    mov word [rsi], ax      ; Sonucu geri RSI'nin düşük kısmına yaz

    ; Orta düşük 16-bitler
    mov ax, word [rsi+2]
    adc ax, word [rdi+2]
    mov word [rsi+2], ax

    ; Orta yüksek 16-bitler
    mov ax, word [rsi+4]
    adc ax, word [rdi+4]
    mov word [rsi+4], ax

    ; En yüksek 16-bitler
    mov ax, word [rsi+6]
    adc ax, word [rdi+6]
    mov word [rsi+6], ax

    ; Sonucun adresini RAX'e yükle, RAX fonksiyonun dönüş değeri olarak kullanılır
    mov rax, rsi

    pop rbp
    ret

16 16 16 16  = 64 bit 