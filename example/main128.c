#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

// Assembly'deki fonksiyonun prototipini tanımla
extern long long* sum128(long long* a, long long* b);

// 128-bit sayıyı iki 64-bitlik kısma bölen fonksiyon
void parse128(const char* str, long long* high, long long* low) {
    size_t len = strlen(str);
    char buffer[65] = {0};  // 64 karakter + null terminator

    // Sayının son 16 karakterini al (en düşük anlamlı 64-bit)
    if (len > 16) {
        strcpy(buffer, str + len - 16);
        *low = strtoull(buffer, NULL, 10);
        memset(buffer, 0, sizeof(buffer));
        strncpy(buffer, str, len - 16);
    } else {
        *low = strtoull(str, NULL, 10);
    }

    // Kalan kısmı al (en yüksek anlamlı 64-bit)
    if (len > 16) {
        *high = strtoull(buffer, NULL, 10);
    } else {
        *high = 0;
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <number1> <number2>\n", argv[0]);
        return -1;
    }

    long long a[2];  // a sayısını tutacak dizi
    long long b[2];  // b sayısını tutacak dizi

    // Sayıları parse et
    parse128(argv[1], &a[1], &a[0]);
    parse128(argv[2], &b[1], &b[0]);

    // Sonucu hesapla
    long long* result = sum128((long long*)a, (long long*)b);

    // Sonucu yazdır
    printf("Toplam: %lld\n", *result);

    return 0;
}