#include "uls.h"

static void lexisort(t_App *app);
static void swap_files_names(t_list **prev, t_list **curr);

void mx_print_args_error(t_App *app) {
    if (!app->flags[f])
        lexisort(app);

    for (t_list *cur = app->args_error; cur != NULL; cur = cur->next) {
        mx_printerr("uls: ");
        mx_printerr((char *)(cur->data));
        mx_printerr(": No such file or directory\n");
    }
}

static void lexisort(t_App *app) {
    t_list *prev = app->args_error;
    t_list *curr = prev->next;
    bool flag = 0;

    while (curr) {
        flag = 0;
        if (mx_strcmp(prev->data, curr->data) > 0) {
            swap_files_names(&prev, &curr);
            flag = 1;
            prev = app->args_error;
            curr = prev->next;
        }
        if (!flag) {
            prev = curr;
            curr = curr->next;
        }
    }
}

static void swap_files_names(t_list **prev, t_list **curr) {
    char *temp = (*curr)->data;

    (*curr)->data = (*prev)->data;
    (*prev)->data = temp;
}
