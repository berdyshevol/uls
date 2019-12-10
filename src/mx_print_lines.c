#include "uls.h"

void mx_print_lines(t_App *app) {
    t_list *lines = mx_printable_lines(app->cur_dir->raw_lines, app->al, app);
    t_list *tmp = NULL;

    for (t_list *i = lines; i != NULL; i = i->next) {
        mx_printstr((char *)(i->data));
        mx_printstr("\n");
    }
    while (lines != NULL) {
        tmp = lines->next;
        mx_strdel((char **)(&lines->data));
        mx_pop_front(&lines);
        lines = tmp;
    }
}
