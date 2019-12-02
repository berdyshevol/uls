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
    if (argc < 1) exit (1); //заглушка
    t_App *app = new_App();

    mx_read_flags(argv[1], app->flags);
    // app = new_app(argc, argv);
    // readargs_parse_fill(app);
    // make_aligned_lines(app);
    // print_aligned_lines(app);
    // free_app(&app);
    
    
    
    app->command[cformat_size] = format_size_noth;
    app->command[cformat_time] = format_time_full;
    app->command[cfilter] = filter_removehidden;
    app->command[csort] = sort_name;

    
    mx_read_dir(app);
    return 0;
}
