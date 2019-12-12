#include "uls.h"

void mx_free_node_data(t_list *node) {
    if (node != NULL || node->data != NULL) {
//        mx_strdel(&(((t_attr *) (node->data))->inode));  //if node != NULL or if node->data != NULL
//        mx_strdel(&(((t_attr *) (node->data))->chmod));
//        mx_strdel(&(((t_attr *) (node->data))->user));
//        mx_strdel(&(((t_attr *) (node->data))->group));
//        mx_strdel(&(((t_attr *) (node->data))->file_name));
//        mx_strdel(&(((t_attr *) (node->data))->original_fn)); // plus fullname
//        mx_strdel(&(((t_attr *) (node->data))->fullname));
        free((((t_attr *)(node->data))->inode));  //if node != NULL or if node->data != NULL
        free((((t_attr *)(node->data))->chmod));
        free((((t_attr *)(node->data))->user));
        free((((t_attr *)(node->data))->group));
        free((((t_attr *)(node->data))->file_name));
        free((((t_attr *)(node->data))->original_name)); // plus fullname
        free((((t_attr *)(node->data))->fullname));

        free(node->data);
//        free(*node);
//        (*node)->data = NULL;
    }
}

void mx_free_list_attr(t_list **list) {
    t_list *next_node = *list;
    while (next_node != NULL) {
        t_list *cur = next_node;
        next_node = next_node->next;
        mx_free_node_data(cur);
        free(cur);
    }
    *list = NULL;

//    if (list == NULL) return;
//    while (*list) {
//        if ((*list)->data != NULL) {
//            mx_free_node_data(list);
//        }
//        //mx_pop_front(list);
//    }
}

void mx_free_list_strings(t_list *list) {
//    t_list *next_node = *list;
//    while (next_node != NULL) {
//        t_list *cur = next_node;
//        next_node = next_node->next;
//        //mx_strdel((char **)&(cur->data)); // if (cur->data) free(cur->data) -- это строка
//        if (cur->data) {
//            char *s = (char *)(cur->data);
//            free(cur->data);
//        }
//        free(cur);
//    }
//    *list = NULL;
    if (list == NULL) return;
    while(list != NULL) {
        if (list->data != NULL) {
            free(list->data);
        }
        mx_pop_front(&list);
    }
}

void mx_free_raw_lines(t_list **list) {
//    t_list *next_node = *list;
//    while (next_node != NULL) {
//        t_list *cur = next_node;
//        next_node = next_node->next;
//        mx_free_list_strings(&cur);
//        free(cur);
//    }
//    *list = NULL;
    if (list == NULL) return;
    while(*list != NULL) {
        if ((*list)->data != NULL) mx_free_list_strings((*list)->data);
        mx_pop_front(list);
    }
}

void mx_free_lfa(t_lfa *lfa) {
    mx_free_list_attr(&(lfa->list_attr));
    mx_free_raw_lines(&(lfa->raw_lines)); // &(lfa->raw_lines)

    if (lfa->command)
        free(lfa->command);             // if lfa->command != NULL
    if (lfa->dir_path)
        free(lfa->dir_path);            // if lfa->dir_path != NULL

}
