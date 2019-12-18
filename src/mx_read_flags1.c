//
// Created by Oleg Berdyshev on 12/18/19.
//
#include "uls.h"

static void sort_flags_1(char *s, int *fl);
static void sort_flags_2(char *s, int *fl);

void mx_sort_flags(char *s, t_App *app) {
    sort_flags_1(&s[1], app->flags);
    sort_flags_2(&s[1], app->flags);
}

static void sort_flags_1(char *s, int *fl) {
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

