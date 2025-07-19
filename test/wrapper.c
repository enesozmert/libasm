#include "../hdr/tester.h"

void strlenWrapper(t_test_params *params) {
    strlenTester(params->str1, params->str2);
}

void strcmpWrapper(t_test_params *params) {
    strcmpTester(params->str1, params->str2);
}

void strcpyWrapper(t_test_params *params) {
    strcpyTester(params->str1, params->str2);
}

void strdupWrapper(t_test_params *params) {
    strdupTester(params->str1, params->str2);
}

void writeWrapper(t_test_params *params) {
    writeTester(params->str1, params->file_path);
}

void readWrapper(t_test_params *params) {
    readTester(params->str1, params->file_path);
}

void allWrapper(t_test_params *params) {
    strlenTester(params->str1, params->str2);
    strcmpTester(params->str1, params->str2);
    strcpyTester(params->str1, params->str2);
    strdupTester(params->str1, params->str2);
    writeTester(params->str1, params->file_path);
    readTester(params->str1, params->file_path);
}

void autoTestWrapper(t_test_params *params) {
    (void)params;
    autoTest();
}