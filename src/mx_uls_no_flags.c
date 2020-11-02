#include "../inc/uls.h"

void mx_uls_no_flags(char **elements) {
    DIR *dir;
    struct dirent *sd = NULL;
    struct winsize max; //to get window size (colomns)
    ioctl(0, TIOCGWINSZ, &max);
    int n = 0;
    if (elements != NULL)
        for (; elements[n] != NULL; n++);
    else {
        elements = (char **)malloc(2);
        elements[0] = mx_strdup(".");
        elements[1] = NULL;
    }
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
	    
	    int len = 0; //number of elements in "files"
	    for (; files[len] != NULL; len++);
	    
	    int rows = mx_get_rows(files, len, max.ws_col);
	    int col = len / rows;
	    if (len % rows != 0)
		col++;
	    
	    int k; //index of current file;
	    for (int i = 0; i < rows; i++) {
		k = i;
		int el_col = 0; //index of first element of colomn
		for (int j = 0; j < col; j++) {
		    if (files[k] == NULL)
		        break;
		    mx_printstr(files[k]);
		    if (files[k + 1] == NULL)
		        break;
		    char *tabs;
		    if (rows == 1)
		        tabs = "  ";
		    else
		        tabs = mx_get_tabs(rows, el_col, k, files);
		    k += rows;
		    el_col += rows;
		    if (j < col - 1)
		        mx_printstr(tabs);
		    if (rows > 1)
		        free(tabs);
		}
		mx_printchar('\n');
	    }
	    mx_del_strarr(&files);
	    closedir(dir);
	    if (n > 1 && elements[i + 1] != NULL)
	        mx_printchar('\n');
    }
    exit(0);
}

