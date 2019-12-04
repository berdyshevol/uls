#include "uls.h"

static int max_name_len(t_list *list) {
    int max = 0;
    for (t_list *i = list; i != NULL; i = i->next)
        if (mx_strlen(((t_attr *)(i->data))->file_name) > max)
            max = mx_strlen(((t_attr *)(i->data))->file_name);
    return max;
}

static char **array_of_names(t_list *list, int size) {
    char **res = (char **)malloc(sizeof(char *) * (size + 1));
    int i = 0;
    for (t_list *j = list; j != NULL; j = j->next, i++)
        res[i] = mx_strdup(((t_attr *)(j->data))->file_name);
    res[size] = NULL;
    return res;
}

static void print_spaces(int num) {
    for (int d = 0; d <= num; d++) {
        mx_printchar(' ');
    }
}

static void print_names(char **names, int max, int rows, int size) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; i + j < size; j += rows) {
            if (mx_strlen(names[i + j]) < max) {
                mx_printstr(names[i + j]);
                if (i + j < size - rows) 
                    print_spaces(max - mx_strlen(names[i + j]));
            } 
            else {
                mx_printstr(names[i + j]);
                if (i + j < size - rows)
                    mx_printchar(' ');
            }
        }
        mx_printchar('\n');
    }
}

// static void error_print(char *str) {
//     char *err = strerror(errno);
//     mx_printerr("uls: ");
//     mx_printerr(str);
//     mx_printerr(": ");
//     mx_printerr(err);
//     mx_printerr("\n");
//     mx_strdel(&str);
//     mx_strdel(&err);
//     exit(1);
// }

void mx_non_standart(t_list *list) {
    for (t_list *j = list; j != NULL; j = j->next) {
        mx_printstr(j->data);
        mx_printchar('\n');
    }
}

void mx_standart_view(t_list *list) {
    int maxLen = max_name_len(list),
    listSize = mx_list_size(list),
    rows = 0, cols = 0;

    char **names = array_of_names(list, listSize);
    struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    cols = win.ws_col / (maxLen + 1);
    if (listSize % cols)
        rows = listSize / cols + 1;
    else
        rows = listSize / cols;
    print_names(names, maxLen, rows, listSize);
    mx_del_strarr(&names);
}
