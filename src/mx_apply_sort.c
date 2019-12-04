#include "uls.h"

bool cmp_size(void *data1, void *data2);
bool cmp_c_time(void *data1, void *data2);
bool cmp_a_time(void *data1, void *data2);
bool cmp_name(void *data1, void *data2);
bool cmp_m_time(void *data1, void *data2);

void mx_apply_sort(t_App *app) {
    switch (app->command[csort]) {
        case sort_size:
            mx_sort_list(app->cur_dir->list_attr, cmp_size);
            break;
        case sort_ctime:
            mx_sort_list(app->cur_dir->list_attr, cmp_c_time);
            break;
        case sort_atime:
            mx_sort_list(app->cur_dir->list_attr, cmp_a_time);
            break;
        case sort_mtime:
            mx_sort_list(app->cur_dir->list_attr, cmp_m_time);
            break;
        case sort_name:
            mx_sort_list(app->cur_dir->list_attr, cmp_name);
            break;
    } 
}


