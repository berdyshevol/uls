//#include "uls.h"


//
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
//static void remove_next_node(t_list *node) {
//    t_list *tmp = node->next->next;
//    mx_free_node(&(node->next));
//    node->next = tmp;
//}
//
//static bool is_hidden(char *fullname) {
//    bool res = false;
//    char *parsed_name = parse_name(fullname);
//    if (parsed_name[0] == '.') {
//        res = true;
//    }
//    free(parsed_name);
//    return res;
//}
//
//void mx_apply_filters(t_lfa *lfa) {
//    char *str;
//    t_list *la = NULL;
//    if (lfa->list_attr == NULL)
//        return;
//    la = lfa->list_attr;
//    // case when list has only one node
//    str = ((t_attr *)(la->data))->fullname;
//    switch (lfa->command[cfilter]) {
//        case filter_delhidden:
//            if (is_hidden(mx_getstruct(la)->fullname))
//                mx_free_node(&la);
//                mx_pop_front(&la);
//            break;
//        case filter_deldir:
//            if (mx_is_dot_dotdot(mx_getstruct(la)->fullname))
//                mx_free_node(&(la));
//                mx_pop_front(&la);
//            break;
//    }
//
//    if (la->next != NULL){   // case when list has more than one node
//        for (t_list *cur = lfa->list_attr; cur->next != NULL; cur = cur->next) {
//            str = ((t_attr *)(cur->next->data))->fullname;
//            switch (lfa->command[cfilter]) {
//                case filter_delhidden:
//                    if (is_hidden(str))
//                        remove_next_node(cur);
//                    break;
//                case filter_deldir:
//                    if (mx_is_dot_dotdot(str))
//                        remove_next_node(cur);
//                    break;
//            }
//        }
//    }
//}

#include "uls.h"
static void del_file(t_list **list, char *name);
static void next_name(t_list **curr, t_list **prev, char **name, char *rm);

void mx_apply_filters(t_lfa *lfa) {
    t_list *curr = lfa->list_attr;
    char *name = NULL;

    if ((lfa->command[cfilter]) == filter_delhidden) {
        while (curr) {
            name = ((t_attr *)(curr->data))->file_name;
            //name = ((t_attr *)(curr->data))->fullname;
            //char *parsed_name = parse_name(name);
            if (name[0] == '.')
                del_file(&(lfa->list_attr), name);
            curr = curr->next;
            //free(parsed_name);
        }
    }
    else if ((lfa->command[cfilter]) == filter_deldir) {
        del_file(&(lfa->list_attr), ".");
        del_file(&(lfa->list_attr), "..");
    }
}

static void del_file(t_list **list, char *removed) {
    t_list *curr = *list;
    t_list *prev = NULL;
    char *name = ((t_attr *)(curr->data))->file_name;

    if (curr != NULL && mx_strcmp(name, removed) == 0) {
        *list = curr->next;
        mx_free_node(&curr);
        free(curr);
        return;
    }
    next_name(&curr, &prev, &name, removed);
    if (curr == NULL)
        return;
    prev->next = curr->next;
    free(curr);
}

static void next_name(t_list **curr, t_list **prev, char **name, char *rm) {
    while (curr != NULL && mx_strcmp(*name, rm) != 0) {
        (*prev) = (*curr);
        (*curr) = (*curr)->next;
        if ((*curr) != NULL)
            *name = ((t_attr *)((*curr)->data))->file_name;
    }
}

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
//        mx_free_node(curr);
//        return;
//    }
//}
