#include "uls.h"

void mx_print_lines(t_App *app) {
    t_list *lines;

    lines = mx_printable_lines(app->cur_dir->raw_lines, app->flags);
    for (; lines != NULL; lines = lines->next) {
        mx_printstr((char *)(lines->data));
        mx_printstr("\n");
    }
}
