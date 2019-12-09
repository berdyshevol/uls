#include "uls.h"

static char *kylobites(off_t size) {
    return mx_itoa(size);                // TODO: доделать
}

static char *megabytes(off_t size) {
    return mx_itoa(size);                // TODO: доделать
}

static char *gigabytes(off_t size) {
    return mx_itoa(size);                // TODO: доделать
}


char *format_size(off_t size, t_App *app) {
    char *unit[] = {"B", "K", "M", "G"};
    enum {B, K, M, G};
    char *res = NULL;
    char *sizestr = mx_itoa(size);

    switch (app->command[human]) {
        case off:
            res = mx_strdup(sizestr);
            break;
        case on:
            if (size < KILOBYTE) {
                res = mx_strjoin(sizestr, unit[B]);
            }
            else if (size < MEGAOBYTE) {
                char *temp = NULL;
                temp = kylobites(size);
                res = mx_strjoin(temp, unit[K]);
                free(temp);
            }
            else if (size < GIGABYTE) {
                char *temp = NULL;
                temp = megabytes(size);
                res = mx_strjoin(temp, unit[M]);
                free(temp);
            }
            else {
                char *temp = NULL;
                temp = gigabytes(size);
                res = mx_strjoin(temp, unit[M]);
                free(temp);
            }
    }
    free(sizestr);
    return res;
}

