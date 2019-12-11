//
// Created by Oleg Berdyshev on 12/11/19.
//
#include "uls.h"

bool mx_is_dot_dotdot(char *name) {
    bool res = false;
    char *dir = NULL;  //// ------------------
    char *cptr = (char *)mx_memrchr(name, '/', mx_strlen(name));
    if (cptr != NULL) {
        dir = mx_strdup(cptr + 1);
    }
    else
        dir = mx_strdup(name);
    if (mx_strcmp(dir, ".") == 0 || mx_strcmp(dir, "..") == 0)
        res = true;
    free(dir);
    return res;
}

t_attr *mx_getstruct(t_list *node) {
    return (t_attr *)(node->data);
}

