section .text
global sum16

; İki 16-bit sayının toplamını hesaplar
; C prototipi: int sum16(int a, int b);
; Eğer girdi değerleri veya sonuç 16-bitlik değeri aşarsa hata döner (-1).
sum16:
    push bp
    mov bp, sp

    ; rdi ve rsi girdilerinin 16-bit aralığında olduğunu kontrol et
    cmp di, 32767
    jg error
    cmp di, -32768
    jl error
    cmp si, 32767
    jg error
    cmp si, -32768
    jl error

    ; Toplama işlemi
    mov ax, di       ; İlk parametreyi al (a) ve ax'e kopyala
    add ax, si       ; İkinci parametreyi topla (b)
    jo error          ; Eğer taşma olursa error'a git

    movsx eax, ax     ; Sonucu rax'a işaretli genişletme yaparak taşı
    pop bp
    ret

error:
    mov ax, -1       ; Hata durumunda -1 döndür
    pop bp
    ret