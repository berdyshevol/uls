#include "uls.h" 

static void del_file(t_list **list, char *name);
static void next_name(t_list **curr, t_list **prev, char **name, char *rm);

static char *parse_name(char *name) {
    char *res = NULL;
    char *cptr = (char *)mx_memrchr(name, '/', mx_strlen(name));
    if (cptr != NULL) {
        res = mx_strdup(cptr + 1);
    }
    else
        res = mx_strdup(name);
    return res;
}

void mx_apply_filters(t_lfa *lfa) {
    t_list *curr = lfa->list_attr;
    char *name = NULL;

    if ((lfa->command[cfilter]) == filter_delhidden) {
        while (curr) {
            name = ((t_attr *)(curr->data))->file_name;
            char *parsed_name = parse_name(name);
            if (parsed_name[0] == '.')
                del_file(&(lfa->list_attr), name);
            curr = curr->next;
            free(parsed_name);
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
        mx_free_node_data(curr);
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
