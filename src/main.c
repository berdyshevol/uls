#include "uls.h"

static t_App *new_App(void) {
    t_App *app = malloc(sizeof(t_App));
    app->al = malloc(size*sizeof(int));
    app->flags = malloc(size*sizeof(int));
    app->cur_dir = NULL;
    mx_clear_flags(app->al);
    mx_clear_flags(app->flags);
    return app;
}

int main(int argc, char **argv) {
    t_App *app = new_App();
    mx_read_flags(argv, argc, app->flags, &(app->dir_path));
    mx_make_command(app);
    
    // --------------
    mx_read_dir(app);

    // free app
    return 0;
}
