#include "uls.h"

void mx_check_eror_flag(char *s) {
    char flags[] = "1ACRSTUlacfghikmnrstu"; // add more flags if need
    int res = 1;
    int i = 0;

    for (; s[i]; i++) {
        res = mx_get_char_index(flags, s[i]);
        if (res < 0) {
            mx_printerr("uls: illegal option -- ");
            write (2, &s[i], 1);
            mx_printerr("\nusage: uls [-1ACRSTUacfghikmnrstu] [file ...]\n");
            exit(1);
        } 
    }
}
