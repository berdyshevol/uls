#include "uls.h"

bool cmp_size(void *data1, void *data2) {
    if ((t_attr *)data1)->file_size < ((t_attr *)data2)->file_size)
        return true;
    else
        return false; 
}

bool cmp_c_time(void *data1, void *data2) {
    if ((t_attr *)data1)->c_time < (t_attr *)data2)->c_time)
        return true;
    else
        return false; 
}

bool cmp_a_time(void *data1, void *data2) {
    if ((t_attr *)data1)->a_time < (t_attr *)data2)->a_time)
        return true;
    else
        return false; 
}

bool cmp_m_time(void *data1, void *data2) {
    if ((t_attr *)data1)->m_time < (t_attr *)data2)->m_time)
        return true;
    else
        return false; 
}

void apply_sort(t_App *app) {
    int state = app->command[csort];
    switch (state) {
        case sort_nosort:
            break;
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
    }
}
