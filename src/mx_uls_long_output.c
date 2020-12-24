#include "../inc/uls.h"

void mx_uls_long_output(char **files, t_options *opts) {
    int len = 0;
    for (; files[len] != NULL; ++len);
    if (opts) {};

    struct stat buf;
    char *ntime = mx_strnew(100);

    int size_len = mx_get_max_size_len(files);

    for (int i = 0; i < len; ++i) {
        stat(files[i], &buf);

        mx_printint(buf.st_nlink);
        mx_printchar(' ');
        
        struct passwd *ubuf = getpwuid(buf.st_uid);
        if (ubuf == NULL) {
            char *mx_err = "uls: ";
            perror(mx_err);
            exit(1);
        }
        mx_printstr(ubuf->pw_name);
        mx_printchar(' ');

        struct group *gbuf = getgrgid(buf.st_gid);
        if (gbuf == NULL) {
            char *mx_err = "uls: ";
            perror(mx_err);
            exit(1);
        }
        mx_printstr(gbuf->gr_name);
        mx_printchar(' ');

        for (int k = mx_strlen(mx_itoa(buf.st_size)); k < size_len; ++k)
            mx_printchar(' ');
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
