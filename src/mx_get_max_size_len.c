#include "../inc/uls.h"

int mx_get_max_size_len(char **files) {
    struct stat buf;
    int max = 0;
    for (int i = 0; files[i] != NULL; i++) {
        stat(files[i], &buf);
        if (buf.st_size > max) 
            max = buf.st_size;
    }
    return mx_strlen(mx_itoa(max));
}
