#include "uls.h"

void mx_print_args_error(t_App *app) {
    for (t_list *cur = app->args_error; cur != NULL; cur = cur->next) {
        mx_printstr("ls: ");
        mx_printstr((char *)(cur->data));
        mx_printstr(": No such file or directory\n");
    }
}
