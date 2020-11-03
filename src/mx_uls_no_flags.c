#include "../inc/uls.h"

void mx_uls_no_flags(char **elements) {
    //DIR *dir;
    struct winsize max; //to get window size (colomns)
    ioctl(0, TIOCGWINSZ, &max);
    
    int n = 0;
    if (elements != NULL)
        for (; elements[n] != NULL; n++);
    else {
        elements = (char **)malloc(2);
        n = 1;
        elements[0] = mx_strdup(".");
        elements[1] = NULL;
    }
    char **directories = NULL;
    char **files_reg = NULL;
    mx_fill_types(elements, n, &directories, &files_reg);
    if (files_reg != NULL) {
        mx_uls_print_table(files_reg, &max);
        if (directories != NULL)
            mx_printchar('\n');
        mx_del_strarr(&files_reg);
    }
    if (directories != NULL) {
        mx_loop_output_dirs(directories, n, max);
        mx_del_strarr(&directories);
    }
    //mx_del_strarr(&elements);
    
    exit(0);
}

