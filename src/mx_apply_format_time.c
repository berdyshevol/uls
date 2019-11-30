#include "uls.h"

void mx_apply_format_time(t_App *app) {
    printf("hear\n");
    if (app->command[cformat_size] == format_size_noth) {
        for (t_list *cur = app->cur_dir->list_attr;
            cur != NULL;
            cur = cur->next) {
                ((t_attr *)(cur->data))->time = mx_strdup(
                            ctime(&((t_attr *)(cur->data))->m_time));
        }
    }
    else if (app->command[cformat_size] == format_size_h) {
        // TODO: time in human way
    }
}

