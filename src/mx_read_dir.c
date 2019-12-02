#include "uls.h"

// static void print_file(t_App *app);

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
    cd->current_DIR = opendir(app->dir_path);
    mx_produce_list_attr(app);
    mx_apply_filters(app);
    mx_apply_sort(app);
    //make_header(app);
    mx_apply_printmode(app);
    // mx_apply_format(app);
    mx_print_lines(app);

    closedir(cd->current_DIR);
}

// static void print_file(t_App *app) {
//     t_list *list = app->cur_dir->list_attr;
//     while (list) {
//         printf("%lld\t", ((t_attr *)(list->data))->blocks);
//         printf("%s  ", ((t_attr *)(list->data))->chmod);
//         printf("%hu\t", ((t_attr *)(list->data))->links);
//         printf("%s   ", ((t_attr *)(list->data))->user);
//         printf("%s   ", ((t_attr *)(list->data))->group);
//         printf("%lld\t", ((t_attr *)(list->data))->file_size);
//         printf("%ld   ", ((t_attr *)(list->data))->a_time);
//         printf("%ld   ", ((t_attr *)(list->data))->m_time);
//         printf("%ld   ", ((t_attr *)(list->data))->c_time);
//         printf("%s\n", ((t_attr *)(list->data))->file_name);
//         list = list->next;
//     }
// }
