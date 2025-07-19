#ifndef TESTER_H
#define TESTER_H

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

typedef struct s_test_params{
    int process;
    char *str1;
    char *str2;
    char *file_path;
} t_test_params;

typedef void (*test_func)(t_test_params *params);

extern size_t _ft_strlen(const char *dest);
extern int _ft_strcmp(char *s1, char *s2);
extern char *_ft_strcpy(char *dest, char *src);
extern char *_ft_strdup(const char *s);
extern ssize_t _ft_write(int fd, const void *buf, size_t count);
extern ssize_t _ft_read(int fd, const void *buf, size_t count);

void print_help_message(void);
void print_usage_error(void);
bool checkProcessNumber(int process);

void strlenTester(char *str1, char *str2);
void strcmpTester(char *str1, char *str2);
void strcpyTester(char *str1, char *str2);
void strdupTester(const char *str1, const char *str2);
void writeTester(char *str1, char *file_path);
void readTester(char *str1, char *file_path);

void autoTest(void);
void strlenWrapper(t_test_params *params);
void strcmpWrapper(t_test_params *params);
void strcpyWrapper(t_test_params *params);
void strdupWrapper(t_test_params *params);
void writeWrapper(t_test_params *params);
void readWrapper(t_test_params *params);
void allWrapper(t_test_params *params);
void autoTestWrapper(t_test_params *params);

int processWork(t_test_params *params);

#endif
