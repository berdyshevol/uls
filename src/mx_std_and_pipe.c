#include "uls.h"

void mx_free_list_strings(t_list *list);
void mx_free_raw_lines(t_list **list);

static t_stdinfo *create_info_struct(t_list *list) {
    t_stdinfo *info = (t_stdinfo *) malloc(sizeof(t_stdinfo));
    info->aligned = (int *) malloc(sizeof(int) * 4);
    info->aligned[0] = 1;
    info->aligned[1] = 1;
    info->aligned[2] = 0;
    info->aligned[3] = 0;
    info->listSize = mx_list_size(list);
    info->maxStr = 0;
    return info;
}

static t_list *list_of_lines(t_lfa *app) {
    t_list *row = NULL;
    t_list *res = NULL;
    t_list *cur = app->list_attr;

    for (; cur != NULL; cur = cur->next) {
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->inode));
        mx_push_back(&row, mx_itoa(((t_attr *)(cur->data))->blocks));
        mx_push_back(&row,
                     (void *)mx_strdup(((t_attr *)(cur->data))->file_name));
        mx_push_back(&res, (void *)row);
        row = NULL;
    }
    return res;
}

static char **array_of_names(t_list *list, int size) {
    char **res = (char **)malloc(sizeof(char *) * (size + 1));
    int i = 0;
    for (t_list *j = list; j != NULL; j = j->next, i++)
        res[i] = mx_strdup(j->data);
    res[size] = NULL;
    return res;
}

static void mx_non_standart(t_list *list) {
    for (t_list *j = list; j != NULL; j = j->next) {
        mx_printstr(j->data);
        mx_printchar('\n');
    }
}

void mx_std_and_pipe(t_lfa *app) {
    t_stdinfo *info = create_info_struct(app->list_attr);
    t_list *some = list_of_lines(app);
    t_list *lines = mx_printable_lines(some, info->aligned, app);
    char **names = array_of_names(lines, info->listSize);

    terminal_size(info, lines, app);
    if (isatty(1) && app->command[cview] != view_one_per_line)
        print_names(names, info);
    else {
        if (app->command[cview] == view_many_per_line)
            print_names(names, info);
        else
            mx_non_standart(lines);
    }
    mx_free_list_strings(lines);
    mx_free_raw_lines(&some);
    free(info->aligned);
    info->aligned = NULL;
    free(info);
    info = NULL;
}
