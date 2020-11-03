#pragma once
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include "../libmx/inc/libmx.h"

typedef struct s_options
{
    bool using_a;
    bool using_l;
}              t_options;

void mx_init_options(t_options *opts);
void mx_uls_print_table(char **files, struct winsize *max);
void mx_uls_no_flags(char **elements);
void mx_flag_l(char* dir_name);
void mx_sort_strarr(char **arr);
char **mx_exclude_hidden(char **arr);
void mx_uls_usage(void);
char *mx_get_tabs(int rows, int col, int curr, char **files);
int mx_get_rows(char **files, int len, int ws_col);
char *mx_get_flags(int argc, char **argv);
bool mx_check_flag(char c);
char **mx_get_elements(int argc, char **argv);
void mx_set_options(t_options *opts, char *flags);
void mx_fill_types(char **elements, int n, char ***directories, char ***files);
void mx_loop_output_dirs(char **elements, int n, struct winsize max);

