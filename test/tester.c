#include "../hdr/tester.h"
#include "../hdr/color.h"

int processWork(t_test_params *params)
{
    char *processes[] = {"strlen", "strcmp", "strcpy", "strdup", "write", "read", "all", "auto"};
    test_func testFunctions[] = {
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
