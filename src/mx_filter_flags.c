#include "uls.h"

static void filter_one(char *s, int *fl);
static void filter_two(char *s, int *fl);
static void filter_three(char *s, int *fl);
static void filter_four(char *s, int *fl);

void mx_filter_flags(char *argv, int *fl) {
    filter_one(argv, fl);
    filter_two(argv, fl);
    filter_three(argv, fl);
    filter_four(argv, fl);
    for (; *argv; argv++)
        if (*argv == 's')
            fl[s] = 1;
}

static void filter_one(char *s, int *fl) {
	for (; *s; s++)
		switch (*s)	{
            case 'f':
                fl[f] = 1;
                break;
            case 'g':
                fl[g] = 1;
                break;
            case 'h':
                fl[h] = 1;
                break;
            case 'o':
                fl[o] = 1;
                break;
            case 'k':
                fl[k] = 1;
                break;
        }
}

static void filter_two(char *s, int *fl) {
	for (; *s; s++)
		switch (*s)	{
            case 'B':
                fl[B] = 1;
                break;
            case 'F':
                fl[F] = 1;
                break;
            case 'H':
                fl[H] = 1;
                break;
            case 'L':
                fl[L] = 1;
                break;
            case 'P':
                fl[P] = 1;
                break;
        }
}

static void filter_three(char *s, int *fl) {
	for (; *s; s++)
		switch (*s)	{
            case 'T':
                fl[T] = 1;
                break;
            case 'b':
                fl[b] = 1;
                break;
            case 'd':
                fl[d] = 1;
                break;
            case 'i':
                fl[i] = 1;
                break;
            case 'n':
                fl[n] = 1;
                break;
        }
}

static void filter_four(char *s, int *fl) {
    for (; *s; s++)
		switch (*s)	{
            case 'p':
                fl[p] = 1;
                break;
            case 'q':
                fl[q] = 1;
                break;
            case 'r':
                fl[r] = 1;
                break;
            case 'w':
                fl[w] = 1;
                break;
            case 'x':
                fl[x] = 1;
                break;
        }
}
