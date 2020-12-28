#include "../inc/uls.h"

void mx_loop_output_dirs(char **elements, int n, struct winsize max, t_options *opts) {
    DIR* dir = NULL;
    struct dirent *sd = NULL;
    char *str;
    for (int i = 0; elements[i] != NULL; i++) {
            if (n > 1) {
                mx_printstr(elements[i]);
                mx_printstr(":\n");
                dir = opendir(elements[i]);
            }
            else
	        dir = opendir(elements[i]);
	    
	    if (dir == NULL) {
			mx_printerr("uls"); //change for errno with perror
			exit(1);
	    }
	    
	    str = NULL;
	    while ((sd = readdir(dir)) != NULL) {
			str = mx_strjoin(str, sd->d_name);
			str = mx_strjoin(str, " ");
	    }
	    
	    char **files = NULL;
	    files = mx_strsplit(str, ' ');

		if (!opts->using_f)
			mx_sort_strarr(files, opts);
		if ((!opts->using_a && opts->using_A) || (!opts->using_a && !opts->using_A))
	    	files = mx_exclude_hidden(files, opts);
	    free(str);
		
		if (!opts->using_f) {
			if (opts->using_t)
				mx_sort_t(files, mx_strjoin(elements[i], "/"), opts);
			else if (opts->using_S)
				mx_sort_S(files, mx_strjoin(elements[i], "/"), opts);
		}

	    if (files != NULL) {
			if (opts->using_m)
				mx_print_m(files, &max, mx_strjoin(elements[i], "/"), opts);
			else if(opts->using_C)
	        	mx_uls_print_table(files, &max, mx_strjoin(elements[i], "/"), opts);
			else
				mx_uls_long_output(files, mx_strjoin(elements[i], "/"), opts);

	        mx_del_strarr(&files);
	    }
	    closedir(dir);
	    if (n > 1 && elements[i + 1] != NULL)
	        mx_printchar('\n');
    }
}

