#include "uls.h"

static void free_list(t_list *head);
static void reading_argv(char *argument, t_App *app);

int main(int argc, char **argv) {
    t_App *app = mx_new_app();
    char **head = argv;
    int num = argc;

    while (--num)
        reading_argv(*++head, app);
    mx_make_command(app);
    mx_read_args(argc, argv, app);
    mx_print_args_error(app);
    mx_print_args_file(app);
    mx_print_args_directories(app);
    free_list(app->args_error); //free
    free_list(app->args_files);
    free_list(app->args_directories);
    free(app->al);
    free(app->flags);
    free(app);
    //system("leaks -q uls");
    return 0;
}

static void reading_argv(char *argument, t_App *app) {
    if (mx_strcmp(argument, "--") == 0) {
        app->stop_flag = true;
        app->is_any_flags++;
    }   
    else if (argument[0] == '-' && !app->stop_flag) {
        mx_read_flags(argument, app);
        app->is_any_flags++;
    }
}

static void free_list(t_list *head) {
    while (head != NULL) {
        mx_pop_front(&head);
    }
}
