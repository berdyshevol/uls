#include "uls.h"

void mx_print_one_directory(char *dirname, t_App *app) {
    t_lfa *lfa = NULL;
    switch (app->command[recursion]) {
        case on:
            lfa = mx_produce_list_attr(dirname, app);
            if (lfa->print_permission_denied) {
                mx_print_permission_denied(dirname);
                break;
            }
            mx_apply(lfa, app);
            // start recursion
            app->command[header_dir] = on;
            for (t_list *cur = lfa->list_attr; cur != NULL; cur = cur->next) {
                if (((t_attr *)(cur->data))->is_dir) {
                    char *fl = ((t_attr *)(cur->data))->original_name;
                    if (mx_is_dot_dotdot(fl)) {
                        continue;
                    }
                    mx_print_one_directory(((t_attr *)(cur->data))->fullname, app);
                }
            }
            break;

        case off:
            lfa = mx_produce_list_attr(dirname, app);
            if (lfa->print_permission_denied) {
                mx_print_permission_denied(dirname);
                break;
            }
            mx_apply(lfa, app);
            break;
    }
    mx_free_lfa(&lfa);
}

