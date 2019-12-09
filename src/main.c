#include "uls.h"

int main(int argc, char **argv) {
    t_App *app = mx_new_app();

    mx_read_flags(argv, argc, app);
    mx_make_command(app);
    mx_read_args(argc, argv, app);
    mx_print_args_error(app);
    mx_print_args_file(app);
    mx_print_args_directories(app);
    //mx_reading(app);

    //system("leaks -q uls");
    return 0;
}
