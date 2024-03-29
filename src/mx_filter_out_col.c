#include "uls.h"

bool mx_is_switched_off(int i, t_lfa *lfa) {
    return (i == at_inode && lfa->command[col_inode] == off)
            || (i == at_blocks && lfa->command[col_blocks] == off)
            || (i == at_user && lfa->command[col_user] == off)
            || (i == at_group && lfa->command[col_group] == off);
}

