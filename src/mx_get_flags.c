#include "../inc/uls.h"

char *mx_get_flags(int argc, char **argv) {
    char *res = NULL;
    int j = 0;
    for (int i = 1; i < argc; i++) {
        j = 1;
        if (argv[i][0] == '-') {
            while (argv[i][j] != '\0') {
                char c = argv[i][j];
                if (!mx_check_flag(argv[i][j])) {
                    mx_printerr("uls: illegal option -- ");
                    mx_printerr(&c);
                    mx_printerr("\n");
                    if (res != NULL)
                        free(res);
                    mx_uls_usage();
                }
                char *tmp_res = mx_strjoin(res, &c);
                if (res != NULL)
                    free(res);
                res = mx_strdup(tmp_res);
                free(tmp_res);
                j++;
            }
        }
    }
    return res;
}

