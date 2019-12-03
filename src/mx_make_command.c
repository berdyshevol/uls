#include "uls.h"

void mx_make_command(t_App *app) {
    // default
    app->command[cfilter] = filter_delhidden;
    app->command[csort] = sort_name;
    app->command[cformat_size] = format_size_noth;
    app->command[cview] = view_many_per_line;
    app->command[numerically] = off;
    app->command[col_inode] = off;
    app->command[col_blocks] = off;
    app->command[col_group] = on;
    // 
    app->command[cheader] = header_no; 
    // check flags
    if (app->flags[i]) {
        app->command[col_inode] = on;
    }
    if (app->flags[s]) {
        app->command[col_blocks] = on;
    }
    if (app->flags[o]) {
        app->command[col_group] = off;
        app->flags[l] = on;
    }
    if (app->flags[n]) {
        app->command[numerically] = on;
        app->flags[l] = on;
    }
    if (app->flags[l]) {
        app->command[cview] = view_long_format;
    }


    // TODO: добавить isatty и изменить app->command[cview]

    // app->command[cfilter] = filter_removedir;
    // app->command[csort] = sort_size;
    // app->command[cformat_size] = format_size_noth;
    // app->command[cformat_time] = format_time_full;
    // app->command[cfilter] = filter_removehidden;
    // app->command[csort] = sort_name;
}

