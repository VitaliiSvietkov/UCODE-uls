#include "../inc/uls.h"

char **mx_exclude_hidden(char **arr, t_options *opts) {
    char **res = NULL;
    char *str = NULL;
    int len = 0;
    for (; arr[len] != NULL; len++);

    int i = 0;
    if (opts->using_A) i = 2;
    for (; i < len; i++) {
        if (arr[i][0] == '.' && !opts->using_a && !opts->using_A)
            continue;
        str = mx_strjoin(str, arr[i]);
        str = mx_strjoin(str, " ");
    }

    res = mx_strsplit(str, ' ');
    free(str);
    mx_del_strarr(&arr);
    return res;
}

