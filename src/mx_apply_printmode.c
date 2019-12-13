#include "uls.h"

static void apply_printmode_flag_l(t_lfa *lfa) {
    t_list *row;
    t_list *cur = lfa->list_attr;
    
    for (; cur != NULL; cur = cur->next) {
        row = NULL;
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->inode));
        mx_push_back(&row, mx_itoa(((t_attr *)(cur->data))->blocks));
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->chmod));
        mx_push_back(&row, mx_itoa((int)((t_attr *)(cur->data))->links));
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->user));
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->group));
        mx_push_back(&row,
                     format_size(((t_attr *)(cur->data))->file_size, lfa));
        mx_apply_format_time(row, cur, lfa);
        mx_push_back(&row,
                     (void *)mx_strdup(((t_attr *)(cur->data))->file_name));
        mx_push_back(&(lfa->raw_lines), (void *)row);
    }
}

void mx_apply_printmode(t_lfa *lfa) {
    static bool has_printed_anithing = false;
    lfa->new_line_needed = has_printed_anithing;
    mx_header_dir(lfa);
    if (lfa->list_attr == NULL)
        return;

    switch (lfa->command[cview]) {
        case view_long_format:
            apply_printmode_flag_l(lfa);
            mx_header_total(lfa);
            mx_print_lines(lfa);
            break;
        case view_one_per_line:
            mx_std_and_pipe(lfa);
            break;
        case view_many_per_line: 
            mx_std_and_pipe(lfa);
            break;
        case view_horizontal:
            // TODO: сделать вывод в колонку
            break;
        case view_with_commas:
            // TODO: сделать вывод в колонку
            break;
    }
    has_printed_anithing = true;
}

