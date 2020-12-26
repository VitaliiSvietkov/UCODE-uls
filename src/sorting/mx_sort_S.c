#include "../../inc/uls.h"

void mx_sort_S(char **arr, char *dir_path, t_options *opts) {
    int len = 0;
    for (; arr[len] != NULL; len++);
    
    char *temp = NULL;
    struct stat buf1;
    struct stat buf2;

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < len - 1; i++) {
            char *path1 = mx_strjoin(dir_path, arr[i]);
            lstat(path1, &buf1);
            free(path1);
            for (int j = i + 1; j < len; j++) {
                char *path2 = mx_strjoin(dir_path, arr[j]);
                lstat(path2, &buf2);
                free(path2);
                if (!opts->using_r) {
                    if (buf1.st_size < buf2.st_size) {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
                else
                    if (buf1.st_size > buf2.st_size) {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
            }
        }
    }

    free(dir_path);
}
