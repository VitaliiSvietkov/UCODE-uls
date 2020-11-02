#include "../inc/uls.h"

char *mx_get_flags(int argc, char **argv) {
    char *res = (char *)malloc(1);
    res[0] = '\0';
    int j = 0;
    for (int i = 1; i < argc; i++) {
        j = 1;
        if (argv[i][0] == '-') {
            while (argv[i][j] != '\0') {
                if (!mx_check_flag(argv[i][j])) {
                    mx_printerr("uls: invalid option -- '");
                    mx_printerr(&argv[i][j]);
                    mx_printerr("'\n");
                    free(res);
                    mx_uls_usage();
                }
                mx_realloc(res, mx_strlen(res) + 1);
                res[mx_strlen(res)] = argv[i][j];
                j++;
            }
        }
    }
    return res;
}

