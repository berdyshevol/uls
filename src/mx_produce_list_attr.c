#include "uls.h"

//void mx_produce_list_attr(t_lfa *lfa) {
//    DIR *d = opendir(lfa->dir_path);
//    //lfa->current_DIR = d;
//	struct dirent *entry;
//	lfa->is_dir = true;
//	while ((entry = readdir(d)) != NULL)
//		mx_push_back(&(lfa->list_attr),
//			(void *)mx_make_attr_struct((entry->d_name), lfa));
//
//	closedir(d);
//}

t_lfa *mx_produce_list_attr(char *dirname, t_App *app) { // идет по дериктории и делает имя с дерикторией
    t_lfa *lfa = mx_new_lfa(app, dirname);
    DIR *d = opendir(dirname);
    if (d != NULL) {
        struct dirent *entry;
        lfa->is_dir = true;
        while ((entry = readdir(d)) != NULL) {
            if (mx_apply_filters_ok(entry->d_name, lfa))
                mx_push_back(&(lfa->list_attr),
                         (void *) mx_make_attr_struct((entry->d_name), lfa));
        }

        closedir(d);
    }
    else {
        lfa->print_permission_denied = true;
    }
    return lfa;
}
