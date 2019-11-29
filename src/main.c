#include "uls.h"

t_App *new_App(void){
    t_App *app = malloc(sizeof(t_App));
    app->al = NULL; // attributs for aligning
    app->flags = NULL;
    app->cur_dir = NULL;
    return app;
}

int main(int argc, char *argv[]) {
    printf("Arguments: %d %s\n", argc, argv[0]);

    // app = new_app(argc, argv);
    // readargs_parse_fill(app);
    // make_aligned_lines(app);
    // print_aligned_lines(app);
    // free_app(&app);

    t_App *app = new_App();
    read_dir(app);
    return 0;
}

