#include "uls.h" 

static void del_file(t_list **list, char *name);

void mx_apply_filters(t_App *app) {
    t_list *curr = app->cur_dir->list_attr;

    if ((app->command[cfilter]) == filter_removehidden) {
        while (curr) {
            char *name = ((t_attr *)(curr->data))->file_name;

            if (*name == '.')
                del_file(&app->cur_dir->list_attr, name);
            curr = curr->next;
        }
    }
    else if ((int)(app->command[cfilter]) == filter_removedir) {
        del_file(&app->cur_dir->list_attr, ".");
        del_file(&app->cur_dir->list_attr, "..");
    }
    // while (list) {
    //     printf("%s\n", ((t_attr *)(list->data))->file_name);
    //     list = list->next;
    // }
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
