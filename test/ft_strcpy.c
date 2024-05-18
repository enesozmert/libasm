#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Assembly'deki fonksiyonun prototipini tanımla
extern char* __ft_strcpy(char* dest, char* src);

int main(int ac, char** av) {
    if (ac != 3) {
        return -1;
    }

    if (strcpy(av[1], av[2]) == __ft_strcpy(av[1], av[2])) {
        printf("OK \n s:%s \n o:%s\n", __ft_strcpy(av[1], av[2]), strcpy(av[1], av[2]));
    } else {
        printf("KO \n s:%s \n o:%s\n", __ft_strcpy(av[1], av[2]), strcpy(av[1], av[2]));
    }
    return 0;
}
