//
// Created by Oleg Berdyshev on 12/11/19.
//
#include "uls.h"

void mx_print_permission_denied(char *dirname, t_lfa *lfa, t_App *app) {
    if (app->first_dir_name_needed)
        lfa->command[header_dir] = on;
    lfa->new_line_needed = true;
    mx_header_dir(lfa);
    mx_printerr("uls: ");
    mx_printerr(dirname);
    mx_printerr(": Permission denied\n");
}
