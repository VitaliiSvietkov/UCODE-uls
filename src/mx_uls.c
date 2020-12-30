#include "../inc/uls.h"

void mx_uls(char **elements, t_options *opts) {
    struct winsize max; //to get window size (colomns)
    ioctl(0, TIOCGWINSZ, &max);
    
    int n = 0;
    if (elements != NULL)
        for (; elements[n] != NULL; n++);
    else {
        elements = (char **)malloc(2);
        n = 1;
        elements[0] = mx_strdup(".");
        elements[1] = NULL;
    }
    char **directories = NULL;
    char **files = NULL;
    mx_fill_types(elements, n, &directories, &files);

    
    if (files != NULL) {
        if (opts->using_m)
            mx_print_m(files, &max, NULL, opts);
        else if (opts->using_C || opts->using_x)
            mx_uls_print_table(files, &max, NULL, opts);
        else if (opts->using_l)
            mx_uls_long_output(files, NULL, opts, false);
        if (directories != NULL)
            mx_printchar('\n');
        mx_del_strarr(&files);
    }
    if (directories != NULL) {
        mx_loop_output_dirs(directories, n, max, opts);
        mx_del_strarr(&directories);
    }
    free(opts);
    exit(0);
}

