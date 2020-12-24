#include "../inc/uls.h"

void mx_uls_long_output(char **files, char *dir_path, t_options *opts) {
    int len = 0;
    for (; files[len] != NULL; ++len);
    if (opts) {};

    struct stat buf;
    char *ntime = mx_strnew(100);

    int links_amount_max_len = 0;
    int max_size_len = mx_get_max_size_len(files, &links_amount_max_len, dir_path);

    for (int i = 0; i < len; ++i) {
        char *path = mx_strjoin(dir_path, files[i]);
        stat(path, &buf);
        free(path);

        if (S_ISDIR(buf.st_mode))
            mx_printchar('d');
        if (S_ISREG(buf.st_mode))
            mx_printchar('-');
        if (S_ISFIFO(buf.st_mode))
            mx_printchar('p');
        if (S_ISLNK(buf.st_mode))
            mx_printchar('l');
        if (S_ISBLK(buf.st_mode))
            mx_printchar('b');
        if (S_ISCHR(buf.st_mode))
            mx_printchar('c');
        if ((buf.st_mode & S_IFMT) == S_IFSOCK)
            mx_printchar('s');

        char *permissions = mx_get_permisions_string(&buf);
        mx_printstr(permissions);
        free(permissions);
        mx_printchar(' ');


        for (int k = mx_strlen(mx_itoa(buf.st_nlink)); k < links_amount_max_len; ++k)
            mx_printchar(' ');
        mx_printint(buf.st_nlink);
        mx_printchar(' ');

        struct passwd *ubuf = getpwuid(buf.st_uid);
        if (ubuf == NULL) {
            char *mx_err = "uls";
            perror(mx_err);
            free(dir_path);
            exit(1);
        }
        mx_printstr(ubuf->pw_name);
        mx_printstr("  ");

        struct group *gbuf = getgrgid(buf.st_gid);
        if (gbuf == NULL) {
            char *mx_err = "uls";
            perror(mx_err);
            free(dir_path);
            exit(1);
        }
        mx_printstr(gbuf->gr_name);
        mx_printstr("  ");

        for (int k = mx_strlen(mx_itoa(buf.st_size)); k < max_size_len; ++k)
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
    free(dir_path);
    free(ntime);
}
