#include <stdio.h>
#include "../hdr/tester.h"
#include "../hdr/color.h"

void print_help_message() {
    printf("=========================================================================\n");
    printf(BYEL "Usage: ./a.out [Process Number] [1. String] [2. String] [File Path]\n" reset);
    printf(BBLU "[I]: If you write or read, you must enter the file path.\n" reset);
    printf(BYEL "Process Numbers:\n" reset);
    printf(BYEL "1: strlen\n2: strcmp\n3: strcpy\n4: strdup\n5: write\n6: read\n7: all\n8: auto\n" reset);
    printf(BBLU "help: Show this message\n" reset);
    printf("=========================================================================\n");
}

void print_usage_error() {
    printf(BRED "Usage: ./a.out [Process Number or help] [1. String] [2. String]\n" reset);
}

bool checkProcessNumber(int process)
{
    return process >= 1 && process <= 8;
}
