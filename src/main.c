#include "uls.h"

int main(int argc, char **argv) {
    t_App *app = new_App();

    mx_read_flags(argv, argc, app->flags, &(app->dir_path));
    mx_make_command(app);
    // printf("app->command[cfilter] -> %d\n", app->command[cfilter]);
    // printf("app->command[csort] -> %d\n", app->command[csort]);
    // // printf("app->command[ccolumns] -> %d\n", app->command[ccolumns]);
    // // printf("app->command[comma] -> %d\n", app->command[comma]);
    // printf("app->command[cformat_size] -> %d\n", app->command[cformat_size]);
    // printf("app->command[time_format] -> %d\n", app->command[time_format]);
    // printf("app->command[time_type] -> %d\n", app->command[time_type]);
    // printf("app->command[cview] -> %d\n", app->command[cview]);
    // printf("app->command[cheader] -> %d\n", app->command[cheader]);
    // printf("app->command[numerically] -> %d\n", app->command[numerically]);
    // printf("app->command[col_inode] -> %d\n", app->command[col_inode]);
    // printf("app->command[col_blocks] -> %d\n", app->command[col_blocks]);
    // printf("app->command[col_group] -> %d\n", app->command[col_group]);

    mx_read_dir(app);

    //system("leaks -q  uls");  
    return 0;
}
