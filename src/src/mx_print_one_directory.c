#include "uls.h"


// static t_CD *new_CD(t_App *app) {
//     t_CD *cd = malloc(sizeof(t_CD ));
//     app->cur_dir = cd;
//     // TODO: fill all NULL
//     cd->list_attr = NULL;
//     cd->raw_lines = NULL;
//     return cd;
// }
 
//void mx_print_one_directory(t_lfa *lfa, t_App *app) {
//    switch (lfa->command[recursion]) {
//        case on:
//            mx_produce_list_attr(lfa);
//            mx_apply(lfa);
//            // start recursion
//            app->command[header_dir] = on;
//            DIR *d = opendir(lfa->dir_path);
//            struct dirent *entry;
//            while ((entry = readdir(d)) != NULL) {
//                if (entry->d_type == DT_DIR) {
//                    if (mx_strcmp(entry->d_name, ".") == 0
//                        || mx_strcmp(entry->d_name, "..") == 0) {
//                        continue;
//                    }
//                    printf("%s\n", entry->d_name);
////                    char *full_dir_name = mx_strjoin(lfa->dir_path, entry->d_name);
////                    t_lfa *newlfa = mx_new_lfa(app, full_dir_name);
////                    mx_print_one_directory(newlfa, app);
//                }
//            }
//            break;
//        case off:
//            mx_produce_list_attr(lfa);
//            mx_apply(lfa);
//            break;
//    }
//}

//void walk_trough_directory(t_lfa *lfa_onlydirs, t_App *app) {
//    // apply sorting by name
//    ////lfa_onlydirs->command[csort] = sort_name;  // TODO: не знаю надо это или нет
//    mx_apply_without_printing(lfa_onlydirs);
//    // print contents of directories
//    for (t_list *cur = lfa_onlydirs->list_attr; cur != NULL; cur = cur->next) {
//        mx_print_one_directory(((t_attr *)(cur->data))->original_fn, app);
//    }
//}

static t_attr *getstruct(t_list *node) {
    return (t_attr *)(node->data);
}

bool is_dot_or_dotdot(char *name) {
    bool res = false;
    char *dir = NULL;  //// ------------------
    char *cptr = (char *)mx_memrchr(name, '/', mx_strlen(name));
    if (cptr != NULL) {
        dir = mx_strdup(cptr + 1);
    }
    else
        dir = mx_strdup(name);
    if (mx_strcmp(dir, ".") == 0 || mx_strcmp(dir, "..") == 0)
        res = true;
    free(dir);
    return res;
}

void mx_print_one_directory(char *dirname, t_App *app) {
    t_lfa *lfa = NULL;
    switch (app->command[recursion]) {
        case on:
            lfa = mx_produce_list_attr(dirname, app);
            if (lfa->list_attr == NULL) {
                mx_print_permission_denied(dirname);
                return;
            }
            mx_apply(lfa);
            // start recursion
            app->command[header_dir] = on;
            t_lfa *lfa_onlydirs = mx_new_lfa(app, dirname);  // make lfa of only dirs
            for (t_list *cur = lfa->list_attr; cur != NULL; cur = cur->next) {
                t_attr *t = (t_attr *)(cur->data);
                if (((t_attr *)(cur->data))->is_dir) {
                    if (is_dot_or_dotdot(getstruct(cur)->fullname)) {
                        continue;
                    }
                    char *origin_name = ((t_attr *)(cur->data))->original_fn;
                    char *full_name = ((t_attr *)(cur->data))->fullname;
                    char *file_name = ((t_attr *)(cur->data))->file_name;
                    mx_push_back(&(lfa_onlydirs->list_attr), cur->data);
                }
            }
            //walk_trough_directory(lfa_onlydirs, app);
            mx_apply_without_printing(lfa_onlydirs);
            for (t_list *cur = lfa_onlydirs->list_attr; cur != NULL; cur = cur->next) {
                char *origin_name = ((t_attr *)(cur->data))->original_fn;
                char *full_name = ((t_attr *)(cur->data))->fullname;
                char *file_name = ((t_attr *)(cur->data))->file_name;
                mx_print_one_directory(((t_attr *)(cur->data))->fullname, app); // TODO: рекурсия идет в глубь и не возвращается
            }
            //mx_free_lfa(lfa_onlydirs);
            break;
        case off:
            lfa = mx_produce_list_attr(dirname, app);
            mx_apply(lfa);
            break;
    }
    //mx_free_lfa(lfa);
}

