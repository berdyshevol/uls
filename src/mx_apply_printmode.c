#include "uls.h"

char *mx_format_size(off_t size, t_App *app) {
                                                           // TODO: доделать
    if (app->command[cformat_size] == format_size_noth)
        return mx_strdup(mx_itoa(size));
    return mx_strdup("no size");
}

void mx_apply_printmode_l(t_App *app) {
    for (t_list *cur = app->cur_dir->list_attr;
        cur != NULL;
        cur = cur->next) {
        t_list *row = NULL;
        //какие колонки выводить какие нет
        // Блоки
        mx_push_back(&row, mx_strdup(mx_itoa(((t_attr *)(cur->data))->blocks)));
        // // Chmod
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->chmod));
        // // links
        mx_push_back(&row, mx_strdup(mx_itoa((int)((t_attr *)(cur->data))->links)));
        // // user
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->user));
        // // group
        // mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->group));
        // // file_size
        mx_push_back(&row, mx_format_size(((t_attr *)(cur->data))->file_size, app));
        // // time
        mx_apply_format_time(row, cur, app);
        // name
        //printf("print: %s\n", ((t_attr *)(cur->data))->file_name);
        mx_push_back(&row, (void *)mx_strdup(((t_attr *)(cur->data))->file_name));
        // push the whole row in list if raw lines
        mx_push_back(&(app->cur_dir->raw_lines), (void *)row);
    }
}

void mx_apply_printmode(t_App *app) {
    switch (app->command[cview]) {
        case view_l:
            mx_apply_printmode_l(app);
            break;
        case view_std:
            // TODO: сделать стандартный вывод
            break;
        case view_comma: 
            // TODO: сделать стандартный вывод
            break;
        case view_1:
            // TODO: сделать вывод в колонку
            break;
    }
}

