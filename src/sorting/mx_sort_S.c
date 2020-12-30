#include "../../inc/uls.h"

void mx_sort_S(char **arr, char *dir_path, t_options *opts) {
    int len = 0;
    for (; arr[len] != NULL; len++);
    
    struct stat buf1;
    struct stat buf2;

    for (int i = 0; i < len - 1; i++) {
        char *path1 = mx_strjoin(dir_path, arr[i]);
        lstat(path1, &buf1);
        free(path1);
        int max_index = i;
        for (int j = i + 1; j < len; j++) {
            char *path2 = mx_strjoin(dir_path, arr[j]);
            lstat(path2, &buf2);
            free(path2);
            if (buf1.st_size < buf2.st_size) {
                max_index = j;
            }
            else if (buf1.st_size == buf2.st_size && mx_strcmp(arr[i], arr[j]) > 0) {
                max_index = j;
            }
        }
        char *temp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = temp;
    }

    if (opts->using_r)
        mx_strarr_reverse(arr);

    free(dir_path);
}
