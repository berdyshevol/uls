#include "uls.h"

static void inicialization_app_al(t_App *app) {
    app->al[0] = 1;  //blocks
    app->al[1] = -1; //cmod_code
    app->al[2] = 1;  //number
    app->al[3] = -2; //user_name
    app->al[4] = -2; //group
    app->al[5] = 1;  //size
    app->al[6] = -1; //data
    app->al[7] = 0;  //file_name
}

t_App *new_App(void) {
    t_App *app = malloc(sizeof(t_App));
    
    app->al = malloc(7 * sizeof(int));
    app->flags = malloc(size * sizeof(int));
    app->cur_dir = NULL;
    mx_clear_flags(app->flags);
    inicialization_app_al(app);
    return app;
}

