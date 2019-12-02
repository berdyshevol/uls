#include "uls.h"

//static void print_file(t_App *app);

t_CD *new_CD(t_App *app) {
    t_CD *cd = malloc(sizeof(t_CD ));
    app->cur_dir = cd;
    // TODO: fill all NULL
    cd->list_attr = NULL;
    cd->raw_lines = NULL;
    return cd;
}

void mx_read_dir(t_App *app) {
    t_CD *cd = new_CD(app);
    cd->current_DIR = opendir("./");     // TODO: Это заглушка. убрать позже и сделать для любой директории
    app->command[cfilter] = filter_removedir;
    app->command[csort] = sort_size;

    mx_produce_list_attr(app);
    //print_file(app);

    //mx_apply_filters(app);
    mx_apply_sort(app);
    //print_file(app);

    //make_header(app);
    mx_apply_printmode(app);    
    //mx_apply_format(app);
    
    print_raw_lines(app->cur_dir->raw_lines);
    //mx_read_dir(app);
    //print_file(app);
    closedir(cd->current_DIR);
}

// static void print_file(t_App *app) {
//     t_list *list = app->cur_dir->list_attr;
//     while (list) {
//         printf("%lld   ", ((t_attr *)(list->data))->blocks);
//         printf("%s   ", ((t_attr *)(list->data))->chmod);
//         printf("%hu   ", ((t_attr *)(list->data))->links);
//         printf("%s   ", ((t_attr *)(list->data))->user);
//         printf("%s   ", ((t_attr *)(list->data))->group);
//         printf("%lld   ", ((t_attr *)(list->data))->file_size);
//         printf("%ld   ", ((t_attr *)(list->data))->a_time);
//         printf("%ld   ", ((t_attr *)(list->data))->m_time);
//         printf("%ld      ", ((t_attr *)(list->data))->c_time);
//         printf("%s\n", ((t_attr *)(list->data))->file_name);
//         list = list->next;
//     }
// }
