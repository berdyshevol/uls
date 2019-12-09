#include "uls.h"

enum e_arg_type {is_error, is_file, is_directory};

enum e_arg_type try_argv(char *name) {
    DIR *d = NULL;
    d = opendir(name);
    if (d != NULL) {
        closedir(d);
        return is_directory;
    }
    else {
        if (errno == ENOTDIR) {
            return is_file;
        }
        else
            return is_error;
    }
}

void mx_read_args(int argc, char *argv[], t_App *app) {
    int i = 1;
    if (app->is_any_flags)
        i = 2;
    for (; i < argc; i++) {
        switch (try_argv(argv[i])) {
            case is_error:
                mx_push_back(&(app->args_error), argv[i]);
                break;
            case is_file:
                mx_push_back(&(app->args_files), argv[i]);
                break;
            case is_directory:
                mx_push_back(&(app->args_directories), argv[i]);
                break;
        }
    }
    if (app->args_error == NULL 
        && app->args_files == NULL && app->args_directories == NULL) {
        char *cur_dur_str = mx_strdup("./");
        mx_push_back(&(app->args_directories), cur_dur_str);
    }
}

