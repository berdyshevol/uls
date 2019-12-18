#include "uls.h"

void static do_recursion(t_lfa *lfa, t_App *app);
static bool try_print_dir(char *dirname, t_lfa **lfa, t_App *app);

void mx_print_one_dir(char *dirname, t_App *app) {
    t_lfa *lfa = NULL;

    switch (app->command[recursion]) {
        case on:
            if (try_print_dir(dirname, &lfa, app))
                do_recursion(lfa, app);
            break;
        case off:
            try_print_dir(dirname, &lfa, app);
            break;
    }
    mx_free_lfa(&lfa);
}

void static do_recursion(t_lfa *lfa, t_App *app) {
    app->command[header_dir] = on;
    for (t_list *cur = lfa->list_attr; cur != NULL; cur = cur->next) {
        if (((t_attr *)(cur->data))->is_dir) {
            char *fl = ((t_attr *)(cur->data))->original_name;
            if (mx_is_dot_dotdot(fl)) {
                continue;
            }
            mx_print_one_dir(((t_attr *)(cur->data))->fullname, app);
        }
    }
}

static bool try_print_dir(char *dirname, t_lfa **lfa, t_App *app) {
    *lfa = mx_produce_list_attr(dirname, app);
    if ((*lfa)->print_permission_denied) {
        mx_print_permission_denied(dirname, *lfa, app);
        return false;
    }
    mx_apply(*lfa, app);
    return true;
}

