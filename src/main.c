#include "../inc/uls.h"

int main(int argc, char *argv[]) {
    t_options *opts = (t_options *)malloc(sizeof(t_options));
    mx_init_options(opts);
    
    mx_get_flags(argc, argv, opts);
    char **elements = mx_get_elements(argc, argv);
    
    if (elements != NULL) {
        mx_sort_strarr(elements, opts);
        
        if (opts->using_t)
            mx_sort_t(elements, mx_strjoin(".", "/"), opts);
        else if (opts->using_S)
            mx_sort_S(elements, mx_strjoin(".", "/"), opts);
    }

    mx_uls(elements, opts);
    
    /*switch(argc){
        case 1:
            dir_name = ".";
            mx_uls(dir_name);
            break;
        case 2:
            if(mx_strcmp(argv[1], "-l") != 0) {
                dir_name = argv[1];
                mx_uls(dir_name);
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

