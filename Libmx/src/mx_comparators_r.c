#include "uls.h"

bool mx_cmp_size_r(void *data1, void *data2) {
    if (((t_attr *)data1)->file_size > ((t_attr *)data2)->file_size)
        return true;
    else
        return false;
}

bool mx_cmp_c_time_r(void *data1, void *data2) {
    if (((t_attr *)data1)->c_time > ((t_attr *)data2)->c_time)
        return true;
    else
        return false; 
}

bool mx_cmp_m_time_r(void *data1, void *data2) {
    if (((t_attr *)data1)->m_time > ((t_attr *)data2)->m_time)
        return true;
    else
        return false; 
}

bool mx_cmp_name_r(void *data1, void *data2) {
    if (mx_strcmp(((t_attr *)data1)->file_name,
        ((t_attr *)data2)->file_name) < 0)
        return true;
    else
        return false; 
}

