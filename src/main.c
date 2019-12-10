#include "uls.h"

static void leaks_report();

int main(int argc, char **argv) {
    t_App *app = new_App();

    mx_read_flags(argv, argc, app->flags, &(app->dir_path));
    mx_make_command(app);
    mx_reading(app);

    leaks_report();
    return 0;
}

static void leaks_report() {
    mx_printstr("\033[31;1m");
    mx_printstr("\n\n===================================|");
    mx_printstr("\033[33;1m");
    system("leaks -q uls");
}
