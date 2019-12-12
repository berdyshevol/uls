#include "uls.h"

static void free_list(t_list *head);

int main(int argc, char **argv) {
    t_App *app = mx_new_app();

    mx_read_flags(argv, argc, app);
    mx_make_command(app);
    mx_read_args(argc, argv, app);
    mx_print_args_error(app);
    mx_print_args_file(app);
    mx_print_args_directories(app);

    // free
    free_list(app->args_error);
    free_list(app->args_files);
    free_list(app->args_directories);
    free(app->al);
    free(app->flags);
    free(app);
    system("leaks -q Proj1");
    return 0;
}

static void free_list(t_list *head) {
    while (head != NULL) {
        //if (head->data != NULL) free(head->data);
        mx_pop_front(&head);
    }
}
