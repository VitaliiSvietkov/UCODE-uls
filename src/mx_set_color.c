#include "../inc/uls.h"

void mx_set_color(struct stat *buf) {
    if (S_ISDIR(buf->st_mode))
        mx_printstr(KBLU);
    else if (S_ISFIFO(buf->st_mode))
        mx_printstr(KBRN);
    else if (S_ISLNK(buf->st_mode))
        mx_printstr(KMAG);
    else if (S_ISBLK(buf->st_mode))
        mx_printstr(KBLU);
    else if (S_ISCHR(buf->st_mode))
        mx_printstr(KBLU);
    else if ((buf->st_mode & S_IFMT) == S_IFSOCK)
        mx_printstr(KGRN);
    else if (buf->st_mode & S_IEXEC)
        mx_printstr(KRED);
    else if (S_ISREG(buf->st_mode))
        mx_printstr(KNRM);
}
