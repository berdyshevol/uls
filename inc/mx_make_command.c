#include "uls.h"

void mx_make_command(t_App *app) {
    // default
    app->command[cfilter] = filter_delhidden;
    app->command[csort] = sort_name;
    app->command[cformat_size] = format_size_noth;
    app->command[cview] = view_many_per_line;
    app->command[col_blocks] = off;
    app->command[col_owner] = on;
    app->command[col_author] = on;
    app->command[col_group] = on;
    app->command[col_user] = on;
    app->command[cheader] = header_no;
    // check flags
    if (app->flags[l]) {
        app->command[col_blocks] = off;
        app->command[csort] = sort_mtime;
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

