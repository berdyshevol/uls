#include "uls.h" 

static void del_file(t_list **list, char *name);

void mx_apply_filters(t_App *app) {
    t_list *list = app->cur_dir->list_attr;
    t_list *curr = list;

    if ((app->command[cfilter]) == filter_removehidden) {
        while (curr) {
            char *name = ((t_attr *)(curr->data))->file_name;

            if (*name == '.')
                del_file(&list, name);
            curr = curr->next;
        }
    }
    else if ((int)(app->command[cfilter]) == filter_removedir) {
        del_file(&list, ".");
        del_file(&list, "..");
    }
}

static void del_file(t_list **list, char *removed) {
    t_list *curr = *list;
    t_list *prev = NULL;
    char *name = ((t_attr *)(curr->data))->file_name;

    if (curr != NULL && mx_strcmp(name, removed) == 0) {
        *list = curr->next;
        free(curr);
        return;
    }
    while (curr != NULL && mx_strcmp(name, removed) != 0) {
        prev = curr;
        curr = curr->next;
        if (curr != NULL)
            name = ((t_attr *)(curr->data))->file_name;
    }
    if (curr == NULL)
        return;
    prev->next = curr->next;
    free(curr);
}
