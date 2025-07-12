#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../includes/color.h"

extern int errno;
extern int _ft_strcmp(char *s1, char *s2);
extern char *_ft_strcpy(char *dest, char *src);
extern char *_ft_strdup(const char *s);
extern size_t _ft_strlen(const char *dest);
extern ssize_t _ft_write(int fd, const void *buf, size_t count);

typedef struct {
    int process;
    char *str1;
    char *str2;
    char *file_path;
} TestParams;

typedef void (*TestFunc)(TestParams *params);

void print_help_message() {
    printf("=========================================================================\n");
    printf(BYEL "Usage: ./a.out [Process Number] [1. String] [2. String] [File Path]\n" reset);
    printf(BBLU "[I]: If you write or read, you must enter the file path.\n" reset);
    printf(BYEL "Process Numbers:\n" reset);
    printf(BYEL "1: strlen\n" reset);
    printf(BYEL "2: strcmp\n" reset);
    printf(BYEL "3: strcpy\n" reset);
    printf(BYEL "4: strdup\n" reset);
    printf(BYEL "5: write\n" reset);
    printf(BYEL "6: read\n" reset);
    printf(BYEL "7: all\n" reset);
    printf(BBLU "help: Show this message\n" reset);
    printf("=========================================================================\n");
}

void print_usage_error() {
    printf(BRED "Usage: ./a.out [Process Number or help] [1. String] [2. String]\n" reset);
}

bool checkProcessNumber(int process)
{
    return process >= 1 && process <= 7;
}

void strlenTester(char *str1, char *str2)
{
    size_t len = strlen(str1);
    size_t len2 = _ft_strlen(str2);
    if (len == len2) {
        printf(BGRN "strlen -> OK\n" reset);
        printf(BBLU "[INF_TEST]:: strlen - %ld %s\n", len, reset);
        printf(BBLU "[INF_TEST]:: _ft_strlen - %ld %s\n", len2, reset);
    }
    else {
        printf(BRED "strlen -> KO\n" reset);
        printf(BRED "[INF_TEST]:: strlen - %ld %s\n", len, reset);
        printf(BRED "[INF_TEST]:: _ft_strlen - %ld %s\n", len2, reset);
    }
}

void strcpyTester(char *str1, char *str2)
{
    char *result = _ft_strcpy(str1, str2);
    char *result2 = strcpy(str1,str2);
    printf("ft_strcpy: %s\n", result);
    printf("strcpy: %s\n", result2);
    if (strcmp(strcpy(str1, str2), _ft_strcpy(str1, str2)) == 0)
        printf(BGRN "strcpy -> OK\n" reset);
    else
        printf(BRED "strcpy -> KO\n" reset);
}

void strdupTester(const char *str1, const char *str2)
{
    if (strcmp(strdup(str1), _ft_strdup(str2)) == 0) {
        printf(BGRN "strdup -> OK %s %s %s\n" reset, str1, str2, strerror(errno));
    }
    else
        printf(BRED "strdup -> KO %s %s %s\n" reset, str1, str2, strerror(errno));
}

void strcmpTester(char *str1, char *str2)
{
    if (strcmp(str1, str2) == _ft_strcmp(str1, str2))
        printf(BGRN "strcmp -> OK\n" reset);
    else
        printf(BRED "strcmp -> KO\n" reset);
}

void writeTester(char *str1, char *file_path)
{
    int fd = open(file_path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    bool result = ((size_t)write(fd, str1, strlen(str1)) == strlen(str1)) && ((size_t)write(fd, str1, strlen(str1)) == strlen(str1));
    if (result == true)
        printf(BGRN "write  -> OK\n" reset);
    else
        printf(BRED "write  -> KO\n" reset);
}

void readTester(char *str1, char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    char *buffer = malloc(sizeof(char) * strlen(str1));
    if ((size_t)read(fd, buffer, strlen(str1)) == strlen(str1)) {
        printf(BGRN "read   -> OK\n" reset);
    }
    else
        printf(BRED "read   -> KO\n" reset);
}

void strlenWrapper(TestParams *params) {
    strlenTester(params->str1, params->str2);
}

void strcmpWrapper(TestParams *params) {
    strcmpTester(params->str1, params->str2);
}

void strcpyWrapper(TestParams *params) {
    strcpyTester(params->str1, params->str2);
}

void strdupWrapper(TestParams *params) {
    strdupTester(params->str1, params->str2);
}

void writeWrapper(TestParams *params) {
    writeTester(params->str1, params->file_path);
}

void readWrapper(TestParams *params) {
    readTester(params->str1, params->file_path);
}

void allWrapper(TestParams *params) {
    strlenTester(params->str1, params->str2);
    strcmpTester(params->str1, params->str2);
    strcpyTester(params->str1, params->str2);
    strdupTester(params->str1, params->str2);
    writeTester(params->str1, params->file_path);
    readTester(params->str1, params->file_path);
}

void autoTest() {
    printf(BMAG "\n[Auto Test] Running predefined tests for all functions...\n" reset);

    // ========================
    // strlen TEST CASES
    // ========================
    printf(BYEL "\n[TEST] strlen\n" reset);
    strlenTester("Hello, World!", "Hello, World!");   // Normal
    strlenTester("", "");                             // Empty string
    strlenTester("a", "a");                           // Single char
    strlenTester("😀😃😄😁😆", "😀😃😄😁😆");             // UTF-8 emojis
    strlenTester("abc\0hidden", "abc");               // Embedded NULL

    // ========================
    // strcmp TEST CASES
    // ========================
    printf(BYEL "\n[TEST] strcmp\n" reset);
    strcmpTester("abc", "abc");                       // Equal
    strcmpTester("abc", "abcd");                      // s2 longer
    strcmpTester("abcd", "abc");                      // s1 longer
    strcmpTester("", "");                             // Empty vs empty
    strcmpTester("", "nonempty");                     // Empty vs nonempty
    strcmpTester("nonempty", "");                     // Nonempty vs empty

    // ========================
    // strcpy TEST CASES
    // ========================
    printf(BYEL "\n[TEST] strcpy\n" reset);
    char buf1[50] = {0};
    char buf2[50] = {0};
    strcpyTester(buf1, "copy this");                  // Normal copy
    strcpyTester(buf2, "");                           // Copy empty

    // ========================
    // strdup TEST CASES
    // ========================
    printf(BYEL "\n[TEST] strdup\n" reset);
    strdupTester("Duplicate me!", "Duplicate me!");   // Normal
    strdupTester("", "");                             // Duplicate empty
    // strdupTester(NULL, NULL);                      // Uncomment if you handle NULL safely

    // ========================
    // write TEST CASES
    // ========================
    printf(BYEL "\n[TEST] write\n" reset);
    writeTester("Hello File!\n", "test_output.txt");  // Normal write
    writeTester("", "test_output.txt");               // Write empty
    writeTester("abc", "/dev/full");                  // Write to full device (should fail)
    int bad_fd = -1;
    errno = 0;
    ssize_t ret = _ft_write(bad_fd, "abc", 3);
    if (ret == -1 && errno == EBADF)
        printf(BGRN "write (bad fd) -> OK (errno=%d)\n" reset, errno);
    else
        printf(BRED "write (bad fd) -> KO (ret=%zd errno=%d)\n" reset, ret, errno);

    // ========================
    // read TEST CASES
    // ========================
    printf(BYEL "\n[TEST] read\n" reset);
    readTester("Hello File!\n", "test_output.txt");   // Normal read
    readTester("", "test_output.txt");                // Read empty file
    errno = 0;
    ret = _ft_write(-1, "abc", 3);                     // Try writing with bad fd
    if (ret == -1 && errno == EBADF)
        printf(BGRN "read (bad fd) -> OK (errno=%d)\n" reset, errno);
    else
        printf(BRED "read (bad fd) -> KO (ret=%zd errno=%d)\n" reset, ret, errno);

    printf(BMAG "\n[Auto Test] Completed.\n" reset);

    // Clean up
    unlink("test_output.txt");
}


void autoTestWrapper(TestParams *params) {
    (void)params;
    autoTest();
}

int processWork(TestParams *params)
{
    char *processes[] = {"strlen", "strcmp", "strcpy", "strdup", "write", "read", "all"};
    TestFunc testFunctions[] = {
        strlenWrapper,
        strcmpWrapper,
        strcpyWrapper,
        strdupWrapper,
        writeWrapper,
        readWrapper,
        allWrapper,
        autoTestWrapper
    };

    printf("=========================================================================\n");
    printf(BYEL "Testing :: %s\n" reset, processes[params->process - 1]);
    printf("=========================================================================\n");

    if (params->process >= 1 && params->process <= 8) {
        testFunctions[params->process - 1](params);
    } else {
        print_usage_error();
        return 1;
    }

    printf("=========================================================================\n");
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "help") == 0) {
        print_help_message();
        return 0;
    }

    if (ac == 2 && strcmp(av[1], "auto") == 0) {
        autoTest();
        return 0;
    }


    if (ac < 4) {
        print_usage_error();
        return 1;
    }

    TestParams params;
    params.process = atoi(av[1]);
    params.str1 = av[2];
    params.str2 = (params.process < 5) ? av[3] : NULL;
    params.file_path = (params.process >= 5) ? av[4] : NULL;

    if (params.process < 1 || params.process > 7) {
        print_usage_error();
        return 1;
    }

    processWork(&params);
    return 0;
}
