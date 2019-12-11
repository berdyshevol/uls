#include "uls.h"

void mx_free_node_data(t_list *node) {
    mx_strdel(&(((t_attr *)(node->data))->inode));
    mx_strdel(&(((t_attr *)(node->data))->chmod));
    mx_strdel(&(((t_attr *)(node->data))->user));
    mx_strdel(&(((t_attr *)(node->data))->group));
    mx_strdel(&(((t_attr *)(node->data))->file_name));
    free(node->data);
    free(node);
    node->data = NULL;
}
