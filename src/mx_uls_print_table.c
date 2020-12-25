#include "../inc/uls.h"

void mx_uls_print_table(char **files, struct winsize *max, char *dir_path, t_options *opts) {
	int istty = isatty(fileno(stdout));
	
	if (!istty || opts->using_1) {
		mx_print_strarr(files, "\n");
		return;
	}
	struct stat buf;

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

    int k; //index of current file;
    bool reached_end = false;
    for (int i = 0; i < rows; i++) {
	k = i;
	int el_col = 0; //index of first element of colomn
	for (int j = 0; j < col; j++) {
	    if (reached_end && j == col - 1)
	        break;

        char *path = mx_strjoin(dir_path, files[k]);
		lstat(path, &buf);
		free(path);
		
		// Print name of an element
	    mx_printstr(files[k]);
		if (S_ISDIR(buf.st_mode) && opts->using_p)
			mx_printchar('/');

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

	free(dir_path);
}

