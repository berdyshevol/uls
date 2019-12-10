#include "libmx.h"

static int get_len(int number, char flag);
static void fill_str(char **str, int len, int number, char flag);

char *mx_itoa(int nbr) {
    char *str = NULL;
    char flag = 0;
    int len = 0;

    if (nbr == -2147483648)
        return mx_strdup("-2147483648");
    if (nbr < 0) {
        flag = 1;
        nbr *= -1;
    }
    if (nbr == 0)
        return mx_strdup("0");

    len = get_len(nbr, flag);
    str = mx_strnew(len);
    fill_str(&str, len, nbr, flag);

    return str;
}

static int get_len(int number, char flag) {
    int len = 0;

    while (number != 0) {
        number /= 10;
        len++;
    }
    if (flag)
        len++;
    return len;
}

static void fill_str(char **str, int len, int number, char flag) {
    while (len--) {
        (*str)[len] = (number % 10) + 48;
        number /= 10;
    }
    if (flag)
        (*str)[0] = '-';
}
