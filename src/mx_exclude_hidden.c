#include "../inc/uls.h"

char **mx_exclude_hidden(char **arr) {
    char **res = NULL;
    char *str = NULL;
    int len = 0;
    for (; arr[len] != NULL; len++);
    for (int i = 0; i < len; i++) {
        if (arr[i][0] == '.')
            continue;
        str = mx_strjoin(str, arr[i]);
        str = mx_strjoin(str, " ");
    }
    res = mx_strsplit(str, ' ');
    free(str);
    mx_del_strarr(&arr);
    return res;
}

