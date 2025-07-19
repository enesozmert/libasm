#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../hdr/tester.h"

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "help") == 0) {
        print_help_message();
        return 0;
    }

    if (ac < 4 && atoi(av[1]) != 8) {
        print_usage_error();
        return 1;
    }

    t_test_params params;
    params.process = atoi(av[1]);
    params.str1 = av[2];
    params.str2 = (params.process < 7) ? av[3] : NULL;
    params.file_path = (params.process >= 5 && params.process < 7) ? av[4] : NULL;

    if (!checkProcessNumber(params.process)) {
        print_usage_error();
        return 1;
    }

    return processWork(&params);
}
