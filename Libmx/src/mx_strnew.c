#include "libmx.h"

char *mx_strnew(const int size) {
    char *p = NULL;

    if (size < 0)
        return NULL;
    p = (char *) malloc((size + 1) * sizeof(char));
    if (p != NULL)
        for (int i = 0; i < size + 1; i++) {
            p[i] = '\0'; 
        }
    return p;
}

