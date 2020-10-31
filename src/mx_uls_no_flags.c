#include "../inc/uls.h"

void mx_uls_no_flags(void) {
    DIR *dir;
    struct dirent *sd = NULL;
    dir = opendir(".");
    
    if (dir == NULL) {
        mx_printerr("ERROR!\n"); //change for errno
        exit(1);
    }
    
    char *str = NULL;
    while ((sd = readdir(dir)) != NULL) {
        str = mx_strjoin(str, sd->d_name);
        str = mx_strjoin(str, " ");
    }
    
    char **files = NULL;
    files = mx_strsplit(str, ' ');
    mx_sort_strarr(files);
    free(str);
    
    mx_print_strarr(files, "  ");
    mx_del_strarr(&files);
    closedir(dir);
    exit(0);
}

