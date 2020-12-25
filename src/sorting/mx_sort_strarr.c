#include "../../inc/uls.h"

void mx_sort_strarr(char **arr, t_options *opts) {
    int len = 0;
    for (; arr[len] != NULL; len++);
    
    char *temp = NULL;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (opts->using_r)
                if (mx_strcmp(arr[i], arr[j]) < 0) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            else
                if (mx_strcmp(arr[i], arr[j]) > 0) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
        }
    }
}

