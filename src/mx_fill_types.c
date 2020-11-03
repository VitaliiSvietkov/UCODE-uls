#include "../inc/uls.h"

void mx_fill_types(char **elements, int n, char ***directories, char ***files) {
    DIR *dir = NULL;
    char *str_files = NULL;
    char *str_dirs = NULL;
    for (int i = 0; i < n; i++) {
        dir = opendir(elements[i]);
        if (dir == NULL) {
            str_files = mx_strjoin(str_files, elements[i]);
            str_files = mx_strjoin(str_files, " ");
        }
        else {
            str_dirs = mx_strjoin(str_dirs, elements[i]);
            str_dirs = mx_strjoin(str_dirs, " ");
            closedir(dir);
        }
    }
    if (str_files != NULL) {
        *files = mx_strsplit(str_files, ' ');
        free(str_files);
    }
    if (str_dirs != NULL) {
        *directories = mx_strsplit(str_dirs, ' ');
        free(str_dirs);
    }
    
}

