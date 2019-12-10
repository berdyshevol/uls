#include "uls.h"

static void output_flags(char *s, int *fl);
static void hiden_files_and_R(char *s, int *fl);
static void sort_flags(char *s, int *fl);
static void sort_flags_2(char *s, int *fl);

void mx_read_flags(char **s, int argc, int *fl, char **dir_path) {
    int flag = 0;

    if (argc > 1 && s[1][0] == '-') {
        mx_check_eror_flag(&s[1][1]);
        output_flags(s[1], fl);
        if (fl[m] == 1 && fl[C] == 1)
            fl[C] = 0;
        hiden_files_and_R(s[1], fl);
        sort_flags(s[1], fl);
        sort_flags_2(s[1], fl);
        mx_filter_flags(s[1], fl);
        if (argc == 3)
            flag = 2;
    }
    else if (argc == 2)
        flag = 1;
    if (flag)
        *dir_path = mx_strdup(s[flag]);
    else
        *dir_path = mx_strdup("./");
}

static void output_flags(char *s, int *fl) { // must be fist
    for (; *s; s++)
        switch (*s) {
        case 'm':
            mx_clear_flags(fl);
            fl[m] = 1;
            break;
        case '1':
            mx_clear_flags(fl);
            fl[one] = 1;
            break;
        case 'l':
            mx_clear_flags(fl);
            fl[l] = 1;
            break;
        case 'C':
            fl[C] = 1;
            fl[l] = 0;
            fl[one] = 0;
            break;
        }
}

static void hiden_files_and_R(char *s, int *fl) {
    for (int i = 0; s[i] != '\0'; i++)
        switch (s[i]) {
        case 'A':
            if (fl[a] != 1)
                fl[A] = 1;
            break;
        case 'a':
            fl[a] = 1;
            fl[A] = 0;
            break;
        case '@':
            if (fl[l] == 1)
                fl[dog] = 1;
            break;
        case 'R':
            fl[R] = 1;
            break;
        }
}

static void sort_flags(char *s, int *fl) {
    for (; *s; s++)
        switch (*s) {
        case 'S':
            fl[S] = 1;
            fl[t] = 0;
            fl[c] = 0;
            break;
        case 'c':
            if (fl[S] != 1) {
                fl[c] = 1;
                break;
            }
        }
}

static void sort_flags_2(char *s, int *fl) {
    for (; *s; s++)
        switch (*s) {
        case 'u':
                fl[u] = 1;
                fl[U] = 0;
                break;
        case 't':
            if (fl[S] != 1) {
                fl[t] = 1;
                break;
            }
        }
}
