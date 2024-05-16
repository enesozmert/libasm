#include <stdio.h>
#include <stdlib.h>

// Assembly'deki fonksiyonun prototipini tanımla
extern long* sum64(long* a, long* b);

int main(int ac, char** av) {
    if (ac != 3) {
        return -1;
    }
    long a; // 1 milyar
    long b; // 2 milyar

    a = atol(av[1]);
    b = atol(av[2]);
    long *a_ptr = &a;
    long *b_ptr = &b;

    long* result = sum64(&a, &b);  // Sonucu a_ptr'de günceller
    printf("Toplam: %ld\n", *result);  // a_ptr'deki güncellenmiş değeri yazdır
    return 0;
}