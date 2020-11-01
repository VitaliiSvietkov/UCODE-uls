#include "../inc/uls.h"

void mx_uls_no_flags(void) {
    DIR *dir;
    struct dirent *sd = NULL;
    dir = opendir(".");
    
    if (dir == NULL) {
        mx_printerr("ERROR!\n"); //change for errno with perror
        exit(1);
    }
    
    char *str = NULL;
    while ((sd = readdir(dir)) != NULL) {
        str = mx_strjoin(str, sd->d_name);
        str = mx_strjoin(str, " ");
    }
    
    char **files = NULL;
    files = mx_strsplit(str, ' ');
    files = mx_exclude_hidden(files);
    mx_sort_strarr(files);
    free(str);
    
    int len = 0; //number of elements in "files"
    for (; files[len] != NULL; len++);
    
    int rows = len / 11;
    if (len % 11 != 0)
        rows++;
    
    int col = 0;
    if (rows == 1)
        col = len;
    else {
        col = len / 2; //not valid, we need count lengs of names
        if (len % 2 != 0)
            col++;
    }
    
    int k; //index of file;
    for (int i = 0; i < rows; i++) {
        k = i;
        for (int j = 0; j < col; j++) {
            mx_printstr(files[k]);
            char *tabs;
            if (rows == 1)
                tabs = "  ";
            else
                tabs = mx_get_tabs(rows, j * 2, k, files);
            k += rows;
            if (j < col - 1)
                mx_printstr(tabs);
            if (rows > 1)
                free(tabs);
            if (files[k] == NULL)
                break;
        }
        mx_printchar('\n');
    }
    mx_del_strarr(&files);
    closedir(dir);
    exit(0);
}

