section .text
extern malloc
extern __errno_location
extern _ft_strlen
extern _ft_strcpy
global _ft_strdup

; void* malloc(size_t size);
; malloc değer olarak bir size istediği için rdi, rax işlemimiz önemli ayrıca rdi'ye atma sebebimiz ilk argümanı destion olması yüzünden

_ft_strdup:
    push rdi            ; Kaydediciyi kaybetmemek için argümanları kaydediyoruz
    call _ft_strlen     ; Kaydediciyi kaybetmemek için argümanları kaydediyoruz
    inc rax             ; '\0' karakteri için bir byte daha yer ayırıyoruz
    mov rdi, rax        ; Yer ayırmak için ayrılan toplam bellek miktarını rdi'ye aktarıyoruz

    call malloc wrt ..plt         ; Bellek ayırma işlevini çağırıyoruz
    test rax, rax       ; malloc başarılı oldu mu kontrol ediyoruz
    jz _error   ; Eğer malloc başarısız olursa, _malloc_failed etiketine atlıyoruz
    pop rdi             ; Kaydediciyi geri alıyoruz

    mov rsi, rdi        ; _ft_strcpy fonksiyonuna kopyalanacak olan karakter dizisinin adresini rsi'ye aktarıyoruz
    mov rdi, rax        ; _ft_strcpy fonksiyonuna kopyalanacak olan bellek bloğunun adresini rdi'ye aktarıyoruz
    call _ft_strcpy     ; Karakter dizisini kopyalıyoruz
    ret

_error:
	pop		rdi					; clean up stack if malloc fails
	call	__errno_location wrt ..plt	; call the errno function
	mov		rdx, 12			; 12 stands for ENOMEM
	mov		[rax], rdx			; save errro code into rax
	mov		rax, 0				; change rax to 0
	ret							; NULL is returned when malloc fails