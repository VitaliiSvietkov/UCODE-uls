#pragma once
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <dirent.h>
#include "libmx.h"

void mx_uls_no_flags(void);
void mx_sort_strarr(char **arr);
char **mx_exclude_hidden(char **arr);
void mx_uls_usage(void);
char *mx_get_tabs(int rows, int col, int curr, char **files);
int mx_get_rows(char **files, int len, int ws_col);

