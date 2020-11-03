#include "../inc/uls.h"

void mx_loop_output_dirs(char **elements, int n, struct winsize max) {
    DIR* dir = NULL;
    struct dirent *sd = NULL;
    for (int i = 0; elements[i] != NULL; i++) {
            if (n > 1) {
                mx_printstr(elements[i]);
                mx_printstr(":\n");
                dir = opendir(elements[i]);
            }
            else
	        dir = opendir(elements[i]);
	    
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
	    
	    mx_uls_print_table(files, &max);
	    
	    mx_del_strarr(&files);
	    closedir(dir);
	    if (n > 1 && elements[i + 1] != NULL)
	        mx_printchar('\n');
    }
}

