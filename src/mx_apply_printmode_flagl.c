//
// Created by Oleg Berdyshev on 12/17/19.
//
#include "uls.h"


void mx_apply_printmode_flag_l(t_lfa *lfa) {
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
                       mx_frm_size(((t_attr *) (cur->data))->file_size, lfa));
        else
            mx_push_back(&row, mx_majorminor((t_attr *) (cur->data)));
        mx_apply_format_time(row, cur, lfa);
        mx_push_back(&row, (void *)mx_strdup(((t_attr *)(cur->data))->file_name));
        mx_push_back(&(lfa->raw_lines), (void *)row);
    }
}

