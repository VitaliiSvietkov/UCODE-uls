#include "../inc/uls.h"

char *mx_ls_get_acl_inf(const char *file) {
    acl_t acl_file;
    char *str = NULL;

    if (file) {
        acl_file = acl_get_file(file, ACL_TYPE_EXTENDED);
        str = acl_to_text(acl_file, NULL);
        acl_free(acl_file);
        return str;
    } 
    else
    	return NULL;
}

char *mx_get_permisions_string(struct stat *buf, char *path) {
    // For user
    char *result = mx_strnew(10);
    if (buf->st_mode & S_IRUSR)
        mx_strcat(result, "r");
    else
        mx_strcat(result, "-");
    if (buf->st_mode & S_IWUSR)
        mx_strcat(result, "w");
    else
        mx_strcat(result, "-");
    if (buf->st_mode & S_IXUSR)
        mx_strcat(result, "x");
    else
        mx_strcat(result, "-");

    // For groups
    if (buf->st_mode & S_IRGRP)
        mx_strcat(result, "r");
    else
        mx_strcat(result, "-");
    if (buf->st_mode & S_IWGRP)
        mx_strcat(result, "w");
    else
        mx_strcat(result, "-");
    if (buf->st_mode & S_IXGRP)
        mx_strcat(result, "x");
    else
        mx_strcat(result, "-");

    // For others
    if (buf->st_mode & S_IROTH)
        mx_strcat(result, "r");
    else
        mx_strcat(result, "-");
    if (buf->st_mode & S_IWOTH)
        mx_strcat(result, "w");
    else
        mx_strcat(result, "-");
    if (buf->st_mode & S_IXOTH)
        mx_strcat(result, "x");
    else
        mx_strcat(result, "-");

    if (mx_ls_get_xattr(path))
        mx_strcat(result, "@");
    else if (mx_ls_get_acl_inf(path))
        mx_strcat(result, "+");
    else
        mx_strcat(result, " ");
    
    return result;
}
