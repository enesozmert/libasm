section .text
global sum128

; İki 128-bit sayının toplamını hesaplar ve sonucun adresini döndürür
; C prototipi: long* sum128(long* a, long* b);
sum128:
    push rbp
    mov rbp, rsp

    ; RSI ve RDI'den sayıları oku ve 128-bit sayıları sekiz parça halinde topla
    ; Düşük 16-bitler
    mov ax, word [rsi]
    add ax, word [rdi]
    mov word [rsi], ax

    ; 2. 16-bitler
    mov ax, word [rsi+2]
    adc ax, word [rdi+2]
    mov word [rsi+2], ax

    ; 3. 16-bitler
    mov ax, word [rsi+4]
    adc ax, word [rdi+4]
    mov word [rsi+4], ax

    ; 4. 16-bitler
    mov ax, word [rsi+6]
    adc ax, word [rdi+6]
    mov word [rsi+6], ax

    ; 5. 16-bitler
    mov ax, word [rsi+8]
    adc ax, word [rdi+8]
    mov word [rsi+8], ax

    ; 6. 16-bitler
    mov ax, word [rsi+10]
    adc ax, word [rdi+10]
    mov word [rsi+10], ax

    ; 7. 16-bitler
    mov ax, word [rsi+12]
    adc ax, word [rdi+12]
    mov word [rsi+12], ax

    ; En yüksek 16-bitler
    mov ax, word [rsi+14]
    adc ax, word [rdi+14]
    mov word [rsi+14], ax

    ; Sonucun adresini RAX'e yükle, RAX fonksiyonun dönüş değeri olarak kullanılır
    mov rax, rsi

    pop rbp
    ret