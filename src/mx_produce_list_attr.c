#include "uls.h"

void mx_produce_list_attr(t_App *app) {
    struct dirent *entry;
    DIR *d = app->cur_dir->current_DIR;

    if (d) {
        app->is_dir = true;
        while ((entry = readdir(d)) != NULL)
            mx_push_back(&(app->cur_dir->list_attr),
                (void *)mx_make_attr_array((entry->d_name), app));
    }
    else {
        app->is_dir = false;
        mx_push_back(&(app->cur_dir->list_attr),
            (void *)mx_make_attr_array(app->dir_path, app));
    }
}
