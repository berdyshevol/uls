#include "uls.h"

void static fill_std_lignement(t_App *app) {
    app->al[0] = -1;
    app->al[1] = 1;
    app->al[2] = -1;
    app->al[3] = 2;
    app->al[4] = 2;
    app->al[5] = -1;
    app->al[6] = 2;
    app->al[7] = 1;
    app->al[8] = 1;
    app->al[9] = 0;
}

static t_App *new_App(void) {
    t_App *app = malloc(sizeof(t_App));
    app->al = malloc(size * sizeof(int));
    app->flags = malloc(size * sizeof(int));
    app->cur_dir = NULL;
    mx_clear_flags(app->al);
    mx_clear_flags(app->flags);
    
    fill_std_lignement(app);
    return app;
}

void mx_make_command(t_App *app) {
    // default
    app->command[cfilter] = filter_removehidden;
    app->command[csort] = sort_name;
    app->command[cformat_size] = format_size_noth;
    app->command[cview] = view_std;
    app->command[cheader] = header_no;
    // check flags
    if (app->flags[l]) {
        app->command[col_blocks] = off;
        app->command[csort] = sort_mtime;
        app->command[cview] = view_l;
    }

    // TODO: добавить isatty и изменить app->command[cview]

    // app->command[cfilter] = filter_removedir;
    // app->command[csort] = sort_size;
    // app->command[cformat_size] = format_size_noth;
    // app->command[cformat_time] = format_time_full;
    // app->command[cfilter] = filter_removehidden;
    // app->command[csort] = sort_name;
}

int main(int argc, char **argv) {
    t_App *app = new_App();
    mx_read_flags(argv[1], app->flags);
    mx_make_command(app);
    
    // --------------
    mx_read_dir(app);
    // ---------------
    // free_app(&app);
    return 0;
    argc++; //заглушка
}
