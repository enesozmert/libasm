#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Assembly'deki fonksiyonun prototipini tanımla
extern int __ft_strlen(char* dest);

int main(int ac, char** av) {
    if (ac != 2) {
        return -1;
    }

    if (strlen(av[1]) == __ft_strlen(av[1])) {
        printf("OK\n");
    } else {
        printf("KO\n");
    }
    return 0;
}
