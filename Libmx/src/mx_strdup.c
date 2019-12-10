#include "libmx.h"

char *mx_strdup(const char *src) {
    int len = mx_strlen(src);
    char *tmp = mx_strnew(len);
    char *res = mx_strcpy(tmp, src);

    return res;
}

