#include "uls.h"

static void print_total(t_App *app);
static void print_dir_name(t_App *app);

void mx_header_dir(t_App *app) {
    switch (app->command[header_dir]) {
        case on:
            print_dir_name(app);
            break;
        case off:
            break;
    }
}

void mx_header_total(t_App *app) {
    switch (app->command[header_total]) {
        case on:
                print_total(app);
                break;
        case off:
            break;
    }
}

static void print_total(t_App *app) {
    unsigned long total = 0;

    for (t_list *cur = app->cur_dir->list_attr; cur != NULL; cur = cur->next)
        total += ((t_attr *)(cur->data))->blocks;
    mx_printstr("Total: ");
    mx_printint(total);
    mx_printstr("\n");
}

static void print_dir_name(t_App *app) {
    mx_printstr(app->dir_path);
    mx_printstr("\n");
}
