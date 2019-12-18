//
// Created by Oleg Berdyshev on 12/18/19.
//

#include "uls.h"

static void time_and_hiden_files1(t_App *app);
static void time_and_hiden_files2(t_App *app);
static void check_other_flags1(t_App *app);
static void check_other_flags2(t_App *app);

void mx_do_other_flags(t_App *app) {
    time_and_hiden_files1(app);
    time_and_hiden_files2(app);
    check_other_flags1(app);
    check_other_flags2(app);
}

static void time_and_hiden_files1(t_App *app) {
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
}

static void time_and_hiden_files2(t_App *app) {
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

static void check_other_flags1(t_App *app) {
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
}

static void check_other_flags2(t_App *app) {
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

