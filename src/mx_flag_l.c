#include "../inc/uls.h"

void mx_flag_l(char* dir_name) {
    DIR *dir;
    struct dirent *sd = NULL;
    struct stat buf;
    //struct winsize max; //to get window size (colomns)
    char ntime[100];
    //ioctl(0, TIOCGWINSZ, &max);
    dir = opendir(dir_name);
    
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
    files = mx_exclude_hidden(files, NULL);
    //mx_sort_strarr(files);
    free(str);
    
    int len = 0; //number of elements in "files"
    for (; files[len] != NULL; len++);
    for (int i = 0; i < len; i++){
        stat(files[i], &buf);
        mx_printint(buf.st_mode);
        mx_printchar(' ');
        mx_strcpy(ntime, ctime(&buf.st_mtime));
        mx_printstr(ntime);
        mx_printstr(files[i]);
        mx_printchar('\n');
    }
    closedir(dir);
    exit(0);
 }
