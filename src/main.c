#include "../inc/uls.h"

int main(int argc, char *argv[]) {
    char *dir_name;
    t_options opts;
    mx_init_options(&opts);
    char *flags = mx_get_flags(argc, argv);
    if (mx_strlen(flags) == 0) {
        dir_name = ".";
        mx_uls_no_flags(dir_name);
    }
    else {
    
    }
    
    /*switch(argc){
        case 1:
            dir_name = ".";
            mx_uls_no_flags(dir_name);
            break;
        case 2:
            if(mx_strcmp(argv[1], "-l") != 0) {
                dir_name = argv[1];
                mx_uls_no_flags(dir_name);
            }
            else {
                dir_name = ".";
                mx_flag_l(dir_name);
            }
            break;
        case 3:
            if(mx_strcmp(argv[1], "-l") != 0){
                mx_uls_usage();
            }
            else {
                char *dir_name = argv[2];
                mx_flag_l(dir_name);
            }
            break;
        default:
            break;
    }*/
    return 0;
}

