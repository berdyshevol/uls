#include "uls.h"

char *mx_byte_format(off_t size, t_byte *n) {
    off_t t = size / n->b;
    char *res = mx_strnew(3);
    char *tmp = NULL;

    if (t > 9) {
        t = size % n->b < n->half_b ? t : t + 1;
        return mx_itoa(t);
    }
    else {
        res[0] = '0' + t;
        res[1] = '.';
        t = size % n->b;
        tmp = mx_itoa(t);
        if (t < n->fifty_b) 
             res[2] = '0';
        if (t > n->fifty_b && t < n->sto_b)
            res[2] = '1';
        if ((t < n->max_b && t > n->sto_b) && t % n->sto_b < n->fifty_b)
            res[2] = tmp[0];
        if ((t < n->max_b && t > n->sto_b)
            && (t % n->sto_b > n->fifty_b && t % n->sto_b < n->ninety_b))
            res[2] = t / n->sto_b + 49;
        else if ((t < n->max_b && t > n->sto_b) && t % n->sto_b >= n->ninety_b) {
            res[0]++;
            res[2] = '0';
        }
        if (t > n->max_b) {
            res[0]++;
            res[2] = '0';
        }
        free(tmp);

    }
    return res;
}
