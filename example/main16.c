#include <stdio.h>
#include <stdlib.h>

// Assembly'deki fonksiyonun prototipini tanımla
extern int sum16(int a, int b);

int main(int ac, char** av) {
    if (ac != 3) {
        return -1;
    }
    long a; // 1 milyar
    long b; // 2 milyar

    a = atol(av[1]);
    b = atol(av[2]);

    int result = sum16(a, b);  // Sonucu a_ptr'de günceller
    printf("Toplam: %d\n", result);  // a_ptr'deki güncellenmiş değeri yazdır
    return 0;
}
//999 999 999 999 999 99
