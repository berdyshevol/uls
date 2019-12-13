//
// Created by Oleg Berdyshev on 12/11/19.
//
#include "uls.h"

void mx_print_permission_denied(char *dirname) {
    mx_printerr("uls: ");
    mx_printerr(dirname);
    mx_printerr(": Permission denied\n");
}
