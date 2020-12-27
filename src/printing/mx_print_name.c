#include "../../inc/uls.h"

void mx_print_name(char *name, struct stat *buf, t_options *opts) {
    if (opts->using_G)
        mx_set_color(&buf);
    mx_printstr(name);
    mx_printstr(KNRM);
    if (S_ISDIR(buf->st_mode) && (opts->using_p || opts->using_F))
        mx_printchar('/');
    else if (S_ISFIFO(buf->st_mode) && opts->using_F)
        mx_printchar('|');
    else if ((buf->st_mode & S_IEXEC) && opts->using_F)
        mx_printchar('*');
    else if (S_ISLNK(buf->st_mode) && opts->using_F)
        mx_printchar('@');
    else if (((buf->st_mode & S_IFMT) == S_IFSOCK) && opts->using_F)
        mx_printchar('=');
    // WHITEOUT?? '%'
}
