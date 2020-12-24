#include "../inc/uls.h"

char *mx_get_mtime(char *ntime) {
    char *res = mx_strnew(12);
    res = mx_strncpy(res, ntime + 4, 12);
    //res[0] += 32; // To lowercase the first symbol
    return res;
}
