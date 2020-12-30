#include "../../inc/uls.h"

void mx_check_flag(char c, t_options *opts) {
    switch (c) {
        case '1':
            opts->using_1 = true;
            opts->using_l = false;
            opts->using_C = false;
            break;
        case 'A':
            opts->using_A = true;
            break;
        case 'a':
            opts->using_A = false;
            opts->using_a = true;
            break;
        case 'C':
            opts->using_C = true;
            opts->using_1 = false;
            opts->using_l = false;
            break;
        case 'F':
            opts->using_F = true;
            break;
        case 'f':
            opts->using_f = true;
            opts->using_a = true;
            break;
        case 'G':
            opts->using_G = true;
            break;
        case 'i':
            opts->using_i = true;
        case 'l':
            opts->using_l = true;
            opts->using_1 = false;
            opts->using_C = false;
            break;
        case 'm':
            opts->using_m = true;
            break;
        case 'o':
            opts->using_o = true;
            break;
        case 'p':
            opts->using_p = true;
            break;
        case 'r':
            opts->using_r = true;
            break;
        case 'S':
            opts->using_S = true;
            opts->using_t = false;
            break;
        case 's':
            opts->using_s = true;
            break;
        case 'T':
            opts->using_T = true;
            break;
        case 't':
            opts->using_t = true;
            opts->using_S = false;
            break;
        case 'x':
            opts->using_x = true;
            opts->using_C = false;
            opts->using_1 = false;
            opts->using_l = false;
            break;
        /*case 'U':
            opts->using_U = true;
            opts->using_l = false;
            opts->using_s = false;
            //disable color
            break;*/
        default:
                mx_printerr("uls: illegal option -- ");
                write(2, &c, 1);
                mx_printerr("\n");
                mx_uls_usage();
    }
}

