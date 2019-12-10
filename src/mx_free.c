#include "uls.h"

void mx_free_node_data(t_list *node) {
    mx_strdel(&(((t_attr *)(node->data))->inode));  //if node != NULL or if node->data != NULL
    mx_strdel(&(((t_attr *)(node->data))->chmod));
    mx_strdel(&(((t_attr *)(node->data))->user));
    mx_strdel(&(((t_attr *)(node->data))->group));
    mx_strdel(&(((t_attr *)(node->data))->file_name));
    mx_strdel(&(((t_attr *)(node->data))->original_fn)); // plus fullname
    free(node->data);
    node->data = NULL;
}

void mx_free_list_attr(t_list **list) {
    t_list *next_node = *list;
    
    while (next_node != NULL) {
        t_list *cur = next_node;
        mx_free_node_data(cur);
        next_node = next_node->next;
        free(cur);
    }
    *list = NULL;
}

void mx_free_list_strings(t_list **list) {
    t_list *next_node = *list;
    while (next_node != NULL) {
        t_list *cur = next_node;
        next_node = next_node->next;
        mx_strdel((char **)&(cur->data)); // if (cur->data) free(cur->data) -- это строка
        free(cur);
    }
    *list = NULL;
}

void mx_free_raw_lines(t_list **list) {
    t_list *next_node = *list;
    while (next_node != NULL) {
        t_list *cur = next_node;
        next_node = next_node->next;
        mx_free_list_strings(&cur);
        free(cur);
    }
    *list = NULL;
}

void mx_free_lfa(t_lfa *lfa) {
    mx_free_list_attr(&(lfa->list_attr));
    mx_free_raw_lines(&(lfa->list_attr)); // &(lfa->raw_lines)
    free(lfa->command);             // if lfa->command != NULL
    free(lfa->dir_path);            // if lfa->dir_path != NULL
}
