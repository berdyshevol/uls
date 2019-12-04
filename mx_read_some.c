#include "uls.h"

static void mx_read_file(t_App *app) {
    t_CD *cd = new_CD(app);
    cd->current_DIR = NULL;
    app->is_dir = false;
    mx_produce_attr(app);
    mx_apply_filters(app);
    mx_apply_sort(app);
    //make_header(app);
    mx_apply_printmode(app);
    // mx_apply_format(app);
}

void mx_read_some(t_App *app) {
    struct stat sb;
    stat(app->dir_path, &sb);
    if ((sb.st_mode & S_IFMT) == S_IFDIR)
        mx_read_dir(app);
    else 
        mx_read_file(app);
}
