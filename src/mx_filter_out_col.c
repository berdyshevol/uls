#include "uls.h"

bool mx_is_swithed_off(int i, t_App *app) {
    return (i == at_inode && app->command[col_inode] == off)
            || (i == at_blocks && app->command[col_blocks] == off)
            || (i == at_user && app->command[col_user] == off)
            || (i == at_group && app->command[col_group] == off);
}

