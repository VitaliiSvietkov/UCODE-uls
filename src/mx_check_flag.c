#include "../inc/uls.h"

void mx_check_flag(char c, t_options *opts) {
    switch (c) {
        case 'a':
            opts->using_A = false;
            opts->using_a = true;
            break;
        case 'A':
            opts->using_a = false;
            opts->using_A = true;
            break;
        /*case 'G':
            opts->using_G = true;
            break;*/
        case 'l':
            opts->using_l = true;
            break;
        case 's':
            opts->using_s = true;
            break;
        case 'p':
            opts->using_p = true;
            break;
        case 'r':
            opts->using_r = true;
            break;
        case 't':
            opts->using_t = true;
            opts->using_S = false;
            break;
        case 'S':
            opts->using_S = true;
            opts->using_t = false;
            break;
        /*case 'U':
            opts->using_U = true;
            opts->using_l = false;
            opts->using_s = false;
            //disable color
            break;*/
        case '1':
            opts->using_1 = true;
            break;
        default:
                mx_printerr("uls: illegal option -- ");
                write(2, &c, 1);
                mx_printerr("\n");
                mx_uls_usage();
    }
}

