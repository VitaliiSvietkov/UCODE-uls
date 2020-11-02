#include "../inc/uls.h"

void mx_set_options(t_options *opts, char *flags) {
    for (int i = 0; i < mx_strlen(flags); i++) {
        switch (flags[i]) {
            case 'a':
                opts->using_a = true;
                continue;
            case 'l':
                opts->using_l = true;
        }
    }
}

