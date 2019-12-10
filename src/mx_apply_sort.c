#include "uls.h"

static void apply_sort(t_App *app);
static void apply_sort_r(t_App *app);

void mx_apply_sort(t_App *app) {
    switch (app->command[reverse]) {
        case on:
            apply_sort_r(app);
            break;
        case off:
            apply_sort(app);
            break;
    } 
}

static void apply_sort(t_App *app) {
    mx_sort_list(app->cur_dir->list_attr, mx_cmp_name);
    switch (app->command[csort]) {
        case sort_size:
            mx_sort_list(app->cur_dir->list_attr, mx_cmp_size);
            break;
        case sort_ctime:
            mx_sort_list(app->cur_dir->list_attr, mx_cmp_c_time);
            break;
        case sort_mtime:
            mx_sort_list(app->cur_dir->list_attr, mx_cmp_m_time);
            break;
        case sort_name:
            mx_sort_list(app->cur_dir->list_attr, mx_cmp_name);
            break;
    } 
}

static void apply_sort_r(t_App *app) {
    mx_sort_list(app->cur_dir->list_attr, mx_cmp_name_r);
    switch (app->command[csort]) {
        case sort_size:
            mx_sort_list(app->cur_dir->list_attr, mx_cmp_size_r);
            break;
        case sort_ctime:
            mx_sort_list(app->cur_dir->list_attr, mx_cmp_c_time_r);
            break;
        case sort_mtime:
            mx_sort_list(app->cur_dir->list_attr, mx_cmp_m_time_r);
            break;
        case sort_name:
            mx_sort_list(app->cur_dir->list_attr, mx_cmp_name_r);
            break;
    } 
}

