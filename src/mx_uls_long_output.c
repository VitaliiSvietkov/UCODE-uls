#include "../inc/uls.h"

void mx_uls_long_output(char **files, char *dir_path, t_options *opts) {
    int len = 0;
    for (; files[len] != NULL; ++len);
    if (opts) {};

    struct stat buf;
    char *ntime = mx_strnew(100);

    int links_amount_max_len = 0;
    int max_size_len = mx_get_max_size_len(files, &links_amount_max_len, dir_path);

    int total = 0;
    int max_block_size_len = 1;
    for (int i = 0; i < len; ++i) {
        char *path = mx_strjoin(dir_path, files[i]);
        stat(path, &buf);
        total += buf.st_blocks;
        if (opts->using_s) {
            char *new_block_size = mx_itoa(buf.st_blocks);
            if (max_block_size_len < mx_strlen(new_block_size))
                max_block_size_len = mx_strlen(new_block_size);
            free(new_block_size);
        }
    }
    mx_printstr("total ");
    mx_printint(total);
    mx_printchar('\n');

    for (int i = 0; i < len; ++i) {
        char *path = mx_strjoin(dir_path, files[i]);
        lstat(path, &buf);

        // Number of blocks (only with '-s')
        if (opts->using_s) {
            char *block_size = mx_itoa(buf.st_blocks);
            int block_size_int = mx_strlen(block_size);
            free(block_size);
            for (int k = 0; k < max_block_size_len - block_size_int; k++)
                mx_printchar(' ');
            mx_printint(buf.st_blocks);
            mx_printchar(' ');
        }

        // Type of a file
        if (S_ISDIR(buf.st_mode))
            mx_printchar('d');
        if (S_ISREG(buf.st_mode))
            mx_printchar('-');
        if (S_ISFIFO(buf.st_mode))
            mx_printchar('p');
        if (S_ISLNK(buf.st_mode))
            mx_printchar('l');
        if (S_ISBLK(buf.st_mode))
            mx_printchar('b');
        if (S_ISCHR(buf.st_mode))
            mx_printchar('c');
        if ((buf.st_mode & S_IFMT) == S_IFSOCK)
            mx_printchar('s');

        // Permisions
        char *permissions = mx_get_permisions_string(&buf, path);
        mx_printstr(permissions);
        free(permissions);
        mx_printchar(' ');

        // Number of hard links
        for (int k = mx_strlen(mx_itoa(buf.st_nlink)); k < links_amount_max_len; ++k)
            mx_printchar(' ');
        mx_printint(buf.st_nlink);
        mx_printchar(' ');

        // User name
        struct passwd *ubuf = getpwuid(buf.st_uid);
        if (ubuf == NULL) {
            char *mx_err = "uls";
            perror(mx_err);
            free(dir_path);
            exit(1);
        }
        mx_printstr(ubuf->pw_name);
        mx_printstr("  ");

        // Group name
        struct group *gbuf = getgrgid(buf.st_gid);
        if (gbuf == NULL) {
            char *mx_err = "uls";
            perror(mx_err);
            free(dir_path);
            exit(1);
        }
        mx_printstr(gbuf->gr_name);
        mx_printstr("  ");
        
        // Size of an element
        for (int k = mx_strlen(mx_itoa(buf.st_size)); k < max_size_len; ++k)
            mx_printchar(' ');
        mx_printint(buf.st_size);
        mx_printchar(' ');

        // Date of last file change/modification etc.
        mx_strcpy(ntime, ctime(&buf.st_mtime));
        char *mtime = mx_get_mtime(ntime);
        mx_printstr(mtime);
        free(mtime);
        mx_printchar(' ');

        // Name of an element
        mx_print_name(files[i], &buf, opts);
        
        // If link - show the pointed element
        if (S_ISLNK(buf.st_mode)) {
            char link_buf[1024];
            ssize_t len;
            if ((len = readlink(path, link_buf, sizeof(link_buf)-1)) != -1) {
                link_buf[len] = '\0';
                mx_printstr(" -> ");
                mx_printstr(link_buf);
                //should we do like in the above for -F????
            }
        }
        mx_printchar('\n');
        free(path);
    }
    free(dir_path);
    free(ntime);
}
