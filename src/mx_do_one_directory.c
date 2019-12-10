#include "uls.h"


// static t_CD *new_CD(t_App *app) {
//     t_CD *cd = malloc(sizeof(t_CD ));
//     app->cur_dir = cd;
//     // TODO: fill all NULL
//     cd->list_attr = NULL;
//     cd->raw_lines = NULL;
//     return cd;
// }
 
void mx_do_one_directory(t_lfa *lfa) {
    switch (lfa->command[recursion]) {
        case on:

            break;
        case off:
            mx_produce_list_attr(lfa);
            mx_apply(lfa);
            break;
    }
}

