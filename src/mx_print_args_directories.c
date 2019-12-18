#include "uls.h"

void mx_print_args_directories(t_App *app) {
    if (app->args_directories == NULL) return;
    // produce list of file attributes
    t_lfa *lfa = mx_new_lfa(app, "");
    for (t_list *cur = app->args_directories; cur != NULL; cur = cur->next) {
        mx_push_back(&(lfa->list_attr),
                     (void *)mx_make_attr_struct((char *)(cur->data), lfa));
    }
    mx_apply_sort(lfa);
    // print contents of directories
    for (t_list *cur = lfa->list_attr; cur != NULL; cur = cur->next) {
        mx_print_one_dir(((t_attr *) (cur->data))->original_name, app);
    }
    mx_free_lfa(&lfa);
}

