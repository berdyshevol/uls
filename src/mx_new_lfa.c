#include "uls.h"

static void copy_commands(t_App *app, t_lfa *lfa);

t_lfa *mx_new_lfa(t_App *app, char *current_dir) {
    t_lfa *lfa = malloc(sizeof(t_lfa));
    lfa->list_attr = NULL;
    lfa->raw_lines = NULL;
    //DIR *current_DIR;  // TODO: do not need
    //char *dir_name;   // TODO: ----????
    //lfa->command = (int *)(app->command);
    copy_commands(app, lfa);
    lfa->al = (int *)(app->al);
    lfa->dir_path = mx_strdup(current_dir);
    return lfa;
}

static void copy_commands(t_App *app, t_lfa *lfa) {
    lfa->command = malloc(sizeof(int) * MAX_COMMANDS);
    for (int i = 0; i < MAX_COMMANDS; i++)
        lfa->command[i] = app->command[i];
}
