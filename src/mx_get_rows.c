#include "../inc/uls.h"

int mx_get_rows(char **files, int len, int ws_col) {
    int col = 0;
    for (int i = 0; i < len; i++)
        col += (mx_strlen(files[i]) + 2);
    int res = col / ws_col;
    if (col % ws_col != 0)
        res += 1;
    return res;
}

