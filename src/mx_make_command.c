#include "uls.h"

static void default_settings(t_App *app);
static void time_and_hiden_files(t_App *app);
static void check_other_flags(t_App *app);
static void check_sort(t_App *app);

void mx_make_command(t_App *app) {
    default_settings(app);
    if (!(isatty(1)) && !(app->flags[C])) 
        app->command[cview] = view_one_per_line;
    if (app->flags[R]) {
        app->command[recursion] = on;
        app->command[header_dir] = on;
    }
    time_and_hiden_files(app);
    check_other_flags(app);
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
    app->command[header_dir] = off; // TODO: header!
    app->command[header_total] = off;
}

static void time_and_hiden_files(t_App *app) {
    if (app->flags[R]) {
        app->command[recursion] = on;
        app->command[header_dir] = off;
        if (app->flags[l])
            app->command[header_total] = on;
        app->command[cfilter] = filter_delhidden;
    }
    if (app->flags[a])
        app->command[cfilter] = filter_nofilter;
    if (app->flags[A])
        app->command[cfilter] = filter_deldir;
    if (app->flags[t]) {
        app->command[csort] = sort_mtime;
        if (app->flags[c]) {
            app->command[csort] = sort_ctime;
            app->command[time_type] = time_type_c;
        }
        if (app->flags[u])
            app->command[csort] = sort_atime;
        if (app->flags[U])
            app->command[csort] = sort_btime;
    }
    if (app->flags[u])
        app->command[time_type] = time_type_a;
    if (app->flags[U])
        app->command[time_type] = time_type_b;
    if (app->flags[T])
        app->command[time_format] = format_time_full;
    if (app->flags[i])
        app->command[col_inode] = on;
}

static void check_other_flags(t_App *app) {
    if (app->flags[s]) {
        app->command[col_blocks] = on;
        app->command[header_total] = on;
    }
    if (app->flags[o]) {
        app->command[col_group] = off;
        app->flags[l] = on;
    }
    if (app->flags[g]) {
        app->command[col_user] = off;
        app->flags[l] = on;
    }
    if (app->flags[n]) {
        app->command[numerically] = on;
        app->flags[l] = on;
    }
    if (app->flags[r])
        app->command[reverse] = on;
    if (app->flags[l]) {
        app->command[cview] = view_long_format;
        app->command[header_total] = on;
        if (app->flags[c])
            app->command[time_type] = time_type_c;
    }
    if (app->flags[h])
        app->command[human] = on;
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

