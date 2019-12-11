#include "uls.h"

void mx_print_args_error(t_App *app) {
    for (t_list *cur = app->args_error; cur != NULL; cur = cur->next) {
        mx_printerr("uls: ");
        mx_printerr((char *)(cur->data));
        mx_printerr(": No such file or directory\n");
    }
}
