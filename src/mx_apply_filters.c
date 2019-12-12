////---------------------- my version ----------------------------------

#include "uls.h"


//static char *parse_name(char *name) {
//    char *res = NULL;
//    char *cptr = (char *)mx_memrchr(name, '/', mx_strlen(name));
//    if (cptr != NULL) {
//        res = mx_strdup(cptr + 1);
//    }
//    else
//        res = mx_strdup(name);
//    return res;
//}

//static void remove_node(t_list *node, t_list **prev) {
//    t_list *tmp = node->next;
//    mx_free_node_data(node);
//    free(node);
//    *prev = tmp;
//}

//static bool is_hidden(char *fullname) {
//    bool res = false;
//    char *parsed_name = parse_name(fullname);
//    if (parsed_name[0] == '.') {
//        res = true;
//    }
//    free(parsed_name);
//    return res;
//}
static bool is_hidden(char *name) {
    bool res = false;
    if (name[0] == '.') {
        res = true;
    }
    return res;
}

bool mx_apply_filters_ok(char *filename, t_lfa *lfa) {
    switch (lfa->command[cfilter]) {
        case filter_delhidden:
            if (is_hidden(filename)) {
                return false;
            }
        case filter_deldir:
            if (mx_is_dot_dotdot(filename))
                return false;
    }
    return true;
}

bool mx_is_dot_dotdot(char *name) {
    if (mx_strcmp(name, ".") == 0 || mx_strcmp(name, "..") == 0)
        return true;
    return false;
}

//bool apply_filter_to_node(t_list *node, t_list **prev, t_lfa *lfa) {
//    char *fln = ((t_attr *)(node->data))->file_name;
//    switch (lfa->command[cfilter]) {
//        case filter_delhidden:
//            if (is_hidden(fln)) {
//                remove_node(node, prev);
//                return true;
//            }
//            break;
//        case filter_deldir:
//            if (mx_is_dot_dotdot(fln)) {
//                remove_node(node, prev);
//                return true;
//            }
//            break;
//    }
//    return false;
//}

//void mx_apply_filters(t_lfa *lfa) {
//    char *str;
//
//    if (lfa->list_attr == NULL)
//        return;
//    while (apply_filter_to_node(lfa->list_attr, &(lfa->list_attr), lfa)); // удаляем первый ноду пока можно
//    // case with next nodes
//    t_list *cur = lfa->list_attr, *prev = NULL;
//    while (cur != NULL) {
//        prev = cur;
//        cur = cur->next;
//        while (apply_filter_to_node(cur, &prev, lfa));
//    }
//}

////---------------------- old version ----------------------------------
//#include "uls.h"
//static void del_file(t_list **list, char *name);
//static void next_name(t_list **curr, t_list **prev, char **name, char *rm);
//
//void mx_apply_filters(t_lfa *lfa) {
//    t_list *curr = lfa->list_attr;
//    char *name = NULL;
//
//    if ((lfa->command[cfilter]) == filter_delhidden) {
//        while (curr) {
//            name = ((t_attr *)(curr->data))->file_name;
//            //name = ((t_attr *)(curr->data))->fullname;
//            //char *parsed_name = parse_name(name);
//            if (name[0] == '.')
//                del_file(&(lfa->list_attr), name);
//            curr = curr->next;
//            //free(parsed_name);
//        }
//    }
//    else if ((lfa->command[cfilter]) == filter_deldir) {
//        del_file(&(lfa->list_attr), ".");
//        del_file(&(lfa->list_attr), "..");
//    }
//}
//
//static void del_file(t_list **list, char *removed) {
//    t_list *curr = *list;
//    t_list *prev = NULL;
//    char *name = ((t_attr *)(curr->data))->file_name;
//
//    if (curr != NULL && mx_strcmp(name, removed) == 0) {
//        *list = curr->next;
//        mx_free_node_data(curr);
//        free(curr);
//        return;
//    }
//    next_name(&curr, &prev, &name, removed);
//    if (curr == NULL)
//        return;
//    prev->next = curr->next;
//    free(curr);
//}
//
//static void next_name(t_list **curr, t_list **prev, char **name, char *rm) {
//    while (curr != NULL && mx_strcmp(*name, rm) != 0) {
//        (*prev) = (*curr);
//        (*curr) = (*curr)->next;
//        if ((*curr) != NULL)
//            *name = ((t_attr *)((*curr)->data))->file_name;
//    }
//}


////---------------------- new version ----------------------------------
//#include "uls.h"
//
//static void del_file(t_list **list, char *name);
//// static void next_name(t_list **curr, t_list **prev, char **name, char *rm);
//
//void mx_apply_filters(t_lfa *lfa) {
//    t_list *curr = lfa->list_attr;
//    char *name = NULL;
//
//    if ((lfa->command[cfilter]) == filter_delhidden) {
//        while (curr) {
//            name = ((t_attr *)(curr->data))->file_name;
//            char *parsed_name = parse_name(name);
//            if (parsed_name[0] == '.')
//                del_file(&lfa->list_attr, name);
//            curr = curr->next;
//            free(parsed_name);
//        }
//    }
//    else if ((lfa->command[cfilter]) == filter_deldir) {
//        del_file(&lfa->list_attr, ".");
//        del_file(&lfa->list_attr, "..");
//    }
//}
//
//static void del_file(t_list **list, char *removed) {
//    t_list *curr = *list;
//    // t_list *prev = NULL;
//    char *name = ((t_attr *)(curr->data))->file_name;
//
//    if (curr != NULL && mx_strcmp(name, removed) == 0) {
//        *list = curr->next;
//        mx_free_node_data(curr);
//        return;
//    }
//}
