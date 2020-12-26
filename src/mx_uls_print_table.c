#include "../inc/uls.h"

void mx_uls_print_table(char **files, struct winsize *max, char *dir_path, t_options *opts) {
	int istty = isatty(fileno(stdout));
	
	if (!istty || opts->using_1) {
		mx_print_strarr(files, "\n");
		return;
	}
	struct stat buf;
	int max_block_size = 1;
	int total = 0;

    int len = 0; //number of elements in "files"
    for (; files[len] != NULL; len++) {
		if (opts->using_s) {
			char *path = mx_strjoin(dir_path, files[len]);
			lstat(path, &buf);
			total += buf.st_blocks;
			free(path);
			char *block_size_str = mx_itoa(buf.st_blocks);
			if (max_block_size < mx_strlen(block_size_str))
				max_block_size = mx_strlen(block_size_str);
			free(block_size_str);
		}
	}
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

	if (opts->using_s) {
		mx_printstr("total ");
		mx_printint(total);
		mx_printchar('\n');
	}
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
			if (opts->using_s) {
				char *block_size = mx_itoa(buf.st_blocks);
				int block_size_int = mx_strlen(block_size);
				free(block_size);
				for (int k = 0; k < max_block_size - block_size_int; k++)
					mx_printchar(' ');
				mx_printint(buf.st_blocks);
				mx_printchar(' ');
			}
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

