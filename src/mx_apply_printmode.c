#include "uls.h"

char *mx_format_size(off_t size, t_App *app) {
                                                           // TODO: доделать
    if (app->command[cformat_size] == format_size_noth)
        return mx_itoa(size);
    return mx_strdup("no size");
}

void mx_apply_printmode_l(t_App *app) {
    mx_apply_header(app);
    for (t_list *cur = app->cur_dir->list_attr;
        cur != NULL;
        cur = cur->next) {
        t_list *row = NULL;
        //какие колонки выводить какие нет
        // inod
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->inode));
        // Блоки
        mx_push_back(&row, mx_itoa(((t_attr *)(cur->data))->blocks));
        // // Chmod
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->chmod));
        // // links
        mx_push_back(&row, mx_itoa((int)((t_attr *)(cur->data))->links));
        // // user
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->user));
        // // group
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->group));
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
        case view_long_format:
            mx_apply_printmode_l(app);
            mx_print_lines(app); 
            break;
        case view_one_per_line:
            mx_non_standart(app->cur_dir->list_attr); // TODO: доделать вывод. Сейчас -G
            break;
        case view_many_per_line: 
            mx_standart_view(app->cur_dir->list_attr);
            break;
        case view_horizontal:
            // TODO: сделать вывод в колонку
            break;
        case view_with_commas:
            // TODO: сделать вывод в колонку
            break;
    }
}

