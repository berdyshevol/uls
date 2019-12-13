#include "uls.h"

static void output_flags(char *s, int *fl);
static void hiden_files_and_R(char *s, int *fl);
static void sort_flags(char *s, int *fl);
static void sort_flags_2(char *s, int *fl);
 
void mx_read_flags(char *s, t_App *app) {
        mx_check_eror_flag(&s[1]);
		output_flags(s, app->flags);
		if (app->flags[m] == 1 && app->flags[C] == 1)
			app->flags[C] = 0;
		hiden_files_and_R(&s[1], app->flags);
		sort_flags(&s[1], app->flags);
		sort_flags_2(&s[1], app->flags);
		mx_filter_flags(&s[1], app->flags);
}

static void output_flags(char *s, int *fl) {
    for (; *s; s++)
        switch (*s) {
        case 'm':
            fl[C] = 0;
            fl[l] = 0;
            fl[one] = 0;
            fl[m] = 1;
            break;
        case '1':
            fl[C] = 0;
            fl[l] = 0;
            fl[one] = 1;
            fl[m] = 0;
            break;
        case 'l':
            fl[C] = 0;
            fl[l] = 1;
            fl[one] = 0;
            fl[m] = 0;
            break;
        case 'C':
            fl[C] = 1;
            fl[l] = 0;
            fl[one] = 0;
            break;
        }
}

static void hiden_files_and_R(char *s, int *fl)
{
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
