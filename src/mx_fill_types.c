#include "../inc/uls.h"

void mx_fill_types(char **elements, int n, char ***directories, char ***files) {
    //DIR *dir = NULL;
    struct stat st;
    char *str_files = NULL;
    char *str_dirs = NULL;
    for (int i = 0; i < n; i++) {
        if (stat(elements[i], &st) < 0) {
            char *mx_err = "uls: cannot access '";
            mx_err = mx_strjoin(mx_err, elements[i]);
            mx_err = mx_strjoin(mx_err, "'");
            perror(mx_err);
            free(mx_err);
            continue;
        }
        
        if (S_ISDIR(st.st_mode)) {
            str_dirs = mx_strjoin(str_dirs, elements[i]);
            str_dirs = mx_strjoin(str_dirs, " ");
        }
        else {
            str_files = mx_strjoin(str_files, elements[i]);
            str_files = mx_strjoin(str_files, " ");
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

