#include "uls.h"

void mx_print_args_directories(t_App *app) {
    if (app->args_directories == NULL) return;
    //if (app->args_files != NULL) mx_printstr("\n");
    // produce list attr
    t_lfa *lfa_dirasfile = mx_new_lfa(app, "");
    lfa_dirasfile->is_dir = false;
    for (t_list *cur = app->args_directories; cur != NULL; cur = cur->next) {
        mx_push_back(&(lfa_dirasfile->list_attr),
                     (void *)mx_make_attr_struct((char *)(cur->data), lfa_dirasfile));
    }
    // apply sorting by name
    lfa_dirasfile->command[csort] = sort_name;
    mx_apply_without_printing(lfa_dirasfile);
    // print contents of directories
    for (t_list *cur = lfa_dirasfile->list_attr; cur != NULL; cur = cur->next) {
        t_lfa *lfa = mx_new_lfa(app, ((t_attr *)(cur->data))->original_fn);
        lfa->command[header_dir] = on;
        lfa->is_dir = true;
        mx_do_one_directory(lfa);     // HERE RECURSION
        mx_free_lfa(lfa);
    }
    mx_free_lfa(lfa_dirasfile);
}
