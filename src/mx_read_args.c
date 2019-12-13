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
    bool is_one_dir = false; // true if there is at least one directory
    for (; i < argc; i++) {
        switch (try_argv(argv[i])) {
            case is_error:
                mx_push_back(&(app->args_error), argv[i]);
                break;
            case is_file:
                mx_push_back(&(app->args_files),  argv[i]);
                app->command[header_dir] = on;
                break;
            case is_directory:
                if (is_one_dir)
                    app->command[header_dir] = on; // if at least two dirs then turn on flag
                is_one_dir = true;
                mx_push_back(&(app->args_directories),  argv[i]);
                break;
        }
    }
    if (app->args_error == NULL 
        && app->args_files == NULL && app->args_directories == NULL) {
        //app->currentdir = true;
        char *cur_dur_str = ".";
        mx_push_back(&(app->args_directories), cur_dur_str);
    }
}

