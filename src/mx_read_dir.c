#include "uls.h"


static t_CD *new_CD(t_App *app) {
    t_CD *cd = malloc(sizeof(t_CD ));
    app->cur_dir = cd;
    // TODO: fill all NULL
    cd->list_attr = NULL;
    cd->raw_lines = NULL;
    return cd;
}

void mx_reading(t_App *app) {
    t_CD *cd = new_CD(app);
    cd->current_DIR = opendir(app->dir_path);
    mx_produce_list_attr(app);
    mx_apply_filters(app); // TODO: Почистить лики
    mx_apply_sort(app);
    mx_apply_printmode(app);
    // mx_apply_format(app);
    if (cd->current_DIR)
        closedir(cd->current_DIR);
}

