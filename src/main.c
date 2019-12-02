#include "uls.h"

void static fill_std_lignement(t_App *app) {
    app->al[0] = -1;
    app->al[1] = 1;
    app->al[2] = -1;
    app->al[3] = 2;
    app->al[4] = 2;
    app->al[5] = -1;
    app->al[6] = 2;
    app->al[7] = 1;
    app->al[8] = 1;
    app->al[9] = 0;
}

static t_App *new_App(void) {
    t_App *app = malloc(sizeof(t_App));
    app->al = malloc(size * sizeof(int));
    app->flags = malloc(size * sizeof(int));
    app->cur_dir = NULL;
    mx_clear_flags(app->al);
    mx_clear_flags(app->flags);
    
    fill_std_lignement(app);
    return app;
}

int main(int argc, char **argv) {
    t_App *app = new_App();
    mx_read_flags(argv, argc, app->flags, &(app->dir_path));
    mx_make_command(app);
    
    // --------------
    mx_read_dir(app);
    // ---------------
    // free_app(&app);
    return 0;
    argc++; //заглушка
}
