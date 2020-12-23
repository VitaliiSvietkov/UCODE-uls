#include "../inc/uls.h"

void mx_check_flag(char c, t_options *opts) {
    switch (c) {
        case 'a':
            if (opts->using_A)
                opts->using_A = false;
            opts->using_a = true;
            break;
        case 'A':
            if (opts->using_a)
                opts->using_a = false;
            opts->using_A = true;
            break;
        case 'l':
            opts->using_l = true;
            break;
        default:
                mx_printerr("uls: illegal option -- ");
                mx_printerr(&c);
                mx_printerr("\n");
                mx_uls_usage();
    }
}

