#include "uls.h"

void mx_apply_sort(t_App *app) {
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


