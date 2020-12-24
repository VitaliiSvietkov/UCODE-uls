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
		mx_sort_strarr(files);

		if ((!opts->using_a && opts->using_A) || (!opts->using_a && !opts->using_A))
	    	files = mx_exclude_hidden(files, opts);
	    free(str);

	    if (files != NULL) {
			if(!opts->using_l)
	        	mx_uls_print_table(files, &max);
			else
				mx_uls_long_output(files, mx_strjoin(elements[i], "/"), opts);

	        mx_del_strarr(&files);
	    }
	    closedir(dir);
	    if (n > 1 && elements[i + 1] != NULL)
	        mx_printchar('\n');
    }
}

