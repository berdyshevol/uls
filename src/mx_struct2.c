//
// Created by Oleg Berdyshev on 12/18/19.
//

#include "uls.h"

char *mx_get_user(uid_t uid) {
    struct passwd *pws;
    pws = getpwuid(uid);
    return mx_strdup(pws->pw_name);
}

char *mx_get_group(gid_t gid) {
    struct group *g;
    if ((g = getgrgid(gid)) != NULL)
        return mx_strdup(g->gr_name);
    else
        return mx_itoa(gid);
}

char *mx_get_name(struct stat sb, char *file, char *path, t_lfa *app) {
    char link_read[255];
    ssize_t bytes_read;
    char *res = NULL, *tmp = NULL;

    if (S_ISLNK(sb.st_mode) && app->command[cview] == view_long_format) {
        tmp = mx_strjoin(file, " -> ");
        bytes_read = readlink(path, link_read, 254);
        link_read[bytes_read] = '\0';
        res = mx_strjoin(tmp, link_read);
        mx_strdel(&tmp);
    }
    else if ((S_IXUSR & sb.st_mode) || (S_IXGRP & sb.st_mode)
             || (S_IXOTH & sb.st_mode))
        res = mx_strdup(file); //printf("\033[31m%s\033[37m\n", file);
    else if (S_ISFIFO(sb.st_mode))
        res = mx_strdup(file); //printf("\033[33m%s\033[37m\n", file);
    else
        res = mx_strdup(file); //printf("%s\n", file);
    return res;
}

