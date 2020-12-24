#include "../inc/libmx.h"

int mx_strcmp(const char *s1, const char *s2) {
    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);
    for (int i = 0, j = 0; i < len1 && j < len2; i++, j++) {
        char c1 = *s1;
        char c2 = *s2;

        /*Uncomment for ignoring everything non alphabetical*/
        /*if (!mx_isalpha(c1) && !mx_isdigit(c1)) {
            s1++;
            j--;
            continue;
        }
        if (!mx_isalpha(c2) && !mx_isdigit(c2)) {
            s2++;
            i--;
            continue;
        }*/

        /*Uncomment to compare taking into account lowercase*/
        /*if (mx_isupper(c1))
            c1 += 32;
        if (mx_isupper(c2))
            c2 += 32;*/
            
        if (c1 != c2)
            return c1 - c2;
        s1++;
        s2++;
    }
    if (len1 < len2)
        return -1;
    if (len1 > len2)
        return 1;
    return 0;
}

