#include "../../inc/uls.h"

void mx_sort_t(char **arr, char *dir_path) {
    int len = 0;
    for (; arr[len] != NULL; len++);
    
    char *temp = NULL;
    struct stat buf1;
    struct stat buf2;

    for (int i = 0; i < len - 1; i++) {
        char *path1 = mx_strjoin(dir_path, arr[i]);
        lstat(path1, &buf1);
        free(path1);
        for (int j = i + 1; j < len; j++) {
            char *path2 = mx_strjoin(dir_path, arr[j]);
            lstat(path2, &buf2);
            free(path2);
            if (mx_strcmp(arr[i], arr[j]) > 0) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    free(dir_path);
}
