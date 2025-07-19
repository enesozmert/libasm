#include "../hdr/tester.h"
#include "../hdr/color.h"

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
    if (fd < 0) {
        printf(BRED "write -> KO (file open error: %s)\n" reset, strerror(errno));
        return;
    }

    ssize_t sys_write_res = write(fd, str1, strlen(str1));
    lseek(fd, 0, SEEK_SET);
    ssize_t ft_write_res = _ft_write(fd, str1, strlen(str1));
    close(fd);

    if (sys_write_res == ft_write_res && sys_write_res == (ssize_t)strlen(str1))
        printf(BGRN "write  -> OK\n" reset);
    else
        printf(BRED "write  -> KO (sys: %zd, ft: %zd)\n" reset, sys_write_res, ft_write_res);
}


void readTester(char *str1, char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    if (fd < 0) {
        printf(BRED "read -> KO (file open error: %s)\n" reset, strerror(errno));
        return;
    }

    size_t buf_size = strlen(str1) + 1; // Null terminator için +1
    char *sys_buffer = malloc(buf_size);
    char *ft_buffer = malloc(buf_size);
    if (!sys_buffer || !ft_buffer) {
        printf(BRED "read -> KO (malloc failed)\n" reset);
        close(fd);
        return;
    }

    ssize_t sys_read_res = read(fd, sys_buffer, strlen(str1));
    lseek(fd, 0, SEEK_SET);
    ssize_t ft_read_res = _ft_read(fd, ft_buffer, strlen(str1));
    close(fd);

    sys_buffer[sys_read_res] = '\0';
    ft_buffer[ft_read_res] = '\0';

    if (sys_read_res == ft_read_res && strcmp(sys_buffer, ft_buffer) == 0)
        printf(BGRN "read   -> OK\n" reset);
    else
        printf(BRED "read   -> KO (sys: %zd, ft: %zd)\n" reset, sys_read_res, ft_read_res);

    free(sys_buffer);
    free(ft_buffer);
}
