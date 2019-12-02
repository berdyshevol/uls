#include "uls.h"

t_App *new_App(void) {
    t_App *app = malloc(sizeof(t_App));
    app->al = malloc(size*sizeof(int));
    app->flags = malloc(size*sizeof(int));
    app->cur_dir = NULL;
    mx_clear_flags(app->al);
    mx_clear_flags(app->flags);
    return app;
}

