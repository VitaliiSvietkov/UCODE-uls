#include "../inc/uls.h"

void mx_uls_print_table(char **files, struct winsize *max) {
    int len = 0; //number of elements in "files"
    for (; files[len] != NULL; len++);    
    int rows = mx_get_rows(files, len, max->ws_col);
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
}

