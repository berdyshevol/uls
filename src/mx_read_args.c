#include "uls.h"

static enum e_arg_type try_argv(char *name);
static void if_no_filesordirs(t_App *app);
static void do_dir(t_App *app, char *argvi, bool *is_one_dir);

void mx_read_args(int argc, char *argv[], t_App *app) {
    int i = app->is_any_flags;
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
                do_dir(app, argv[i], &is_one_dir);
        }
    }
    if_no_filesordirs(app);
}

static void do_dir(t_App *app, char *argvi, bool *is_one_dir) {
    if (*is_one_dir)
        app->command[header_dir] = on;
    *is_one_dir = true;
    mx_push_back(&(app->args_directories),  argvi);
}

static enum e_arg_type try_argv(char *name) {
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

static void if_no_filesordirs(t_App *app) {
    if (app->args_error == NULL
        && app->args_files == NULL && app->args_directories == NULL) {
        char *cur_dur_str = ".";
        mx_push_back(&(app->args_directories), cur_dur_str);
    }
    if (app->args_files && app->args_directories)
        app->is_file_args = true;
}


