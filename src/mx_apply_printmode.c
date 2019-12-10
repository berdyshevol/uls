#include "uls.h"

static char *format_size(off_t size, t_App *app) {
    if (app->command[cformat_size] == format_size_noth) // TODO: доделать
        return mx_itoa(size);
    return mx_strdup("no size");
}

static void apply_printmode_flag_l(t_App *app) {
    t_list *row;
    t_list *cur = app->cur_dir->list_attr;
    
    for (; cur != NULL; cur = cur->next) {
        row = NULL;
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->inode));
        mx_push_back(&row, mx_itoa(((t_attr *)(cur->data))->blocks));
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->chmod));
        mx_push_back(&row, mx_itoa((int)((t_attr *)(cur->data))->links));
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->user));
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->group));
        mx_push_back(&row,
                    format_size(((t_attr *)(cur->data))->file_size, app));
        mx_apply_format_time(row, cur, app);
        mx_push_back(&row,
                    (void *)mx_strdup(((t_attr *)(cur->data))->file_name));
        mx_push_back(&(app->cur_dir->raw_lines), (void *)row);
    }
}

void mx_apply_printmode(t_App *app) {
    mx_header_dir(app);
    switch (app->command[cview]) {
        case view_long_format:
            apply_printmode_flag_l(app);
            mx_header_total(app);
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
