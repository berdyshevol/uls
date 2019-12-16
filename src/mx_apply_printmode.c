#include "uls.h"

char *mx_majorminor(t_attr *attr) {
    int major_num = attr->major_num;
    int minor_num = attr->minor_num;
    char *s0 = mx_itoa(major_num);
    char *s1 = mx_strjoin(s0, ",  ");
    char *s2 = mx_itoa(minor_num);
    char *s3 = mx_strjoin(s1, s2);
    free(s0);
    free(s1);
    free(s2);
    return s3;
}

static void apply_printmode_flag_l(t_lfa *lfa) {
    t_list *row = NULL;
    t_list *cur = lfa->list_attr;
    
    for (; cur != NULL; cur = cur->next) {
        row = NULL;
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->inode));
        mx_push_back(&row, mx_itoa(((t_attr *)(cur->data))->blocks));
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->chmod));
        mx_push_back(&row, mx_itoa((int)((t_attr *)(cur->data))->links));
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->user));
        mx_push_back(&row, mx_strdup(((t_attr *)(cur->data))->group));
        if (((t_attr *)(cur->data))->c_or_b == false)
            mx_push_back(&row,
                     mx_format_size(((t_attr *)(cur->data))->file_size, lfa));
        else
            mx_push_back(&row,
                         mx_majorminor((t_attr *)(cur->data)));

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
            mx_header_total(lfa);
            mx_std_and_pipe(lfa);
            break;
        case view_many_per_line:
            mx_header_total(lfa);
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

