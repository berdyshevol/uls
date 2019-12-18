#include "uls.h"

static void default_settings(t_App *app);
static void check_sort(t_App *app);

void mx_make_command(t_App *app) {
    default_settings(app);
    if (!(isatty(1)) && !(app->flags[C])) 
        app->command[cview] = view_one_per_line;
    if (app->flags[R]) {
        app->command[recursion] = on;
        app->command[header_dir] = on;
    }
    mx_do_other_flags(app);
    check_sort(app);
}

static void default_settings(t_App *app) {
    app->command[recursion] = off;  
    app->command[cfilter] = filter_delhidden;
    app->command[csort] = sort_name;
    app->command[reverse] = off;
    app->command[human] = off;
    app->command[cview] = view_many_per_line;
    app->command[numerically] = off;
    app->command[time_format] = format_time_short;
    app->command[time_type] = time_type_m;
    app->command[col_inode] = off;
    app->command[col_blocks] = off;
    app->command[col_user] = on;
    app->command[col_group] = on;
    app->command[header_dir] = off;
    app->command[header_total] = off;
}

static void check_sort(t_App *app) {
    if (app->flags[S])
        app->command[csort] = sort_size;
    if (app->flags[f]) {
        app->command[csort] = sort_nosort;
        app->command[cfilter] = filter_nofilter;
    }
    if (app->flags[k])
        app->command[kilobytes] = on;
    if (app->flags[one])
        app->command[cview] = view_one_per_line;
    if (app->flags[m])
        app->command[cview] = view_with_commas;
}

