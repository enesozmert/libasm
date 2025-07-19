#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "../hdr/tester.h"
#include "../hdr/color.h"

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