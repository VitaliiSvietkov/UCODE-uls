#include "../inc/uls.h"

void mx_uls_print_table(char **files, struct winsize *max) {
	int istty = isatty(fileno(stdout));
	
	if (!istty) {
		mx_print_strarr(files, "\n");
		return;
	}
    int len = 0; //number of elements in "files"
    for (; files[len] != NULL; len++);
    int col = mx_get_col(files, len, max->ws_col);
    int rows = len / col;
    if (len % col != 0) {
        rows++;
	}
	int fact_len = len;
	while (fact_len % rows != 0)
		fact_len++;
	col = fact_len / rows;
	/*
	if (col * rows > len && (col * rows - len > rows)) {
		int tmp_len = col * rows;
		while (tmp_len > len) {
			col -= 1;
			tmp_len -= rows;
		}
	}
    printf("%d\n%d\n\n", len, fact_len);
    mx_printint(col);
    mx_printchar('\n');
    mx_printint(rows);
    mx_printchar('\n');
	*/
    int k; //index of current file;
    bool reached_end = false;
    for (int i = 0; i < rows; i++) {
	k = i;
	int el_col = 0; //index of first element of colomn
	for (int j = 0; j < col; j++) {
	    if (reached_end && j == col - 1)
	        break;
	    mx_printstr(files[k]);
	    if (files[k + 1] == NULL) {
	        reached_end = true;
	        break;
	    }
	    char *tabs;
	    if (rows == 1)
	        tabs = "  ";
	    else if (j < col - 1)
	        tabs = mx_get_tabs(rows, el_col, k, files);
	    k += rows;
	    el_col += rows;
	    if (j < col - 1)
	        mx_printstr(tabs);
	    if (rows > 1 && j < col - 1)
	        free(tabs);
	}
	mx_printchar('\n');
    }
}

