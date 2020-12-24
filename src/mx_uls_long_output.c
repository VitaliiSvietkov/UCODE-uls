#include "../inc/uls.h"

void mx_uls_long_output(char **files, t_options *opts) {
    int len = 0;
    for (; files[len] != NULL; ++len);
    if (opts) {};

    struct stat buf;
    char *ntime = mx_strnew(100);

    for (int i = 0; i < len; ++i) {
        stat(files[i], &buf);

        mx_printint(buf.st_size);
        mx_printchar(' ');

        mx_strcpy(ntime, ctime(&buf.st_mtime));
        char *mtime = mx_get_mtime(ntime);
        mx_printstr(mtime);
        free(mtime);
        mx_printchar(' ');

        mx_printstr(files[i]);
        mx_printchar('\n');
    }
    free(ntime);
}
