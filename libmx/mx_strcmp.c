#include "../inc/libmx.h"

/*int mx_strcmp(const char *s1, const char *s2) {
    for (int i = 0; i < s1[i]; i++) {
        if (s1[i] == s2[i]) {
            continue;
        } 
        else {
            if ((int)s1[i] > (int)s2[i]) {
                return ((int)s1[i] - (int)s2[i]);
            }
            else {
                return ((int)s1[i] - (int)s2[i]);
            }
        }
    }
    return 0;
}*/

int mx_strcmp(const char *s1, const char *s2) {
    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);
    for (int i = 0; i < len1 && i < len2; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    if (len1 < len2)
        return -1;
    if (len1 > len2)
        return 1;
    return 0;
}

