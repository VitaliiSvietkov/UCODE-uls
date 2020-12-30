#include "../inc/uls.h"

int main(int argc, char *argv[]) {
    t_options *opts = (t_options *)malloc(sizeof(t_options));
    mx_init_options(opts);
    
    mx_get_flags(argc, argv, opts);
    char **elements = mx_get_elements(argc, argv);
    
    if (elements != NULL) {
        if (!opts->using_f) {
            mx_sort_strarr(elements, opts);
        
            if (opts->using_t)
                mx_sort_t(elements, mx_strjoin(".", "/"), opts);
            else if (opts->using_S)
                mx_sort_S(elements, mx_strjoin(".", "/"), opts);
        }
    }

    mx_uls(elements, opts);
    
    return 0;
}

