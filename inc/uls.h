#pragma once
//#define _POSIX_C_SOURCE
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include "../libmx/inc/libmx.h"

extern int errno;

typedef struct s_options
{
    bool using_a;
    bool using_A;
    bool using_l;
}              t_options;

void mx_uls_usage(void);
void mx_init_options(t_options *opts);
void mx_sort_strarr(char **arr);
char **mx_exclude_hidden(char **arr, t_options *opts);
char **mx_get_elements(int argc, char **argv);
void mx_fill_types(char **elements, int n, char ***directories, char ***files);

char *mx_get_tabs(int rows, int col, int curr, char **files);
int mx_get_col(char **el, int n, int ws_col);
void mx_get_flags(int argc, char **argv, t_options *opts);
void mx_check_flag(char c, t_options *opts);
char *mx_get_mtime(char *ntime);

void mx_loop_output_dirs(char **elements, int n, struct winsize max, t_options *opts);
void mx_uls_print_table(char **files, struct winsize *max);
void mx_uls_long_output(char **files, t_options *opts);

void mx_uls(char **elements, t_options *opts);
void mx_flag_l(char* dir_name);
