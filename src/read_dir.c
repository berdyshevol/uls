#include "uls.h"

t_CD *new_CD(t_App *app) {
    t_CD *cd = malloc(sizeof(t_CD ));
    app->cur_dir = cd;
    cd->list_attr = NULL;
    // TODO: fill all NULL
    
    return cd;
}

void read_dir(t_App *app) {
    t_CD *cd = new_CD(app);
    cd->current_DIR = opendir("./");     // TODO: Это заглушка. убрать позже и сделать для любой директории
    produce_list_attr(app);
    // apply_filters(app);
    //apply_sort(app);
    // apply_format(app);
    // apply_printmode(app);
    // make_header(app);
    closedir(cd->current_DIR);
}
