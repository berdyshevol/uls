#include "uls.h" 

static void del_file(t_list **list, char *name);
// static void next_name(t_list **curr, t_list **prev, char **name, char *rm);

void mx_apply_filters(t_App *app) {
    t_list *curr = app->cur_dir->list_attr;
    char *name = NULL;

    if ((app->command[cfilter]) == filter_delhidden) {
        while (curr) {
            name = ((t_attr *)(curr->data))->file_name;
            if (*name == '.')
                del_file(&app->cur_dir->list_attr, name);
            curr = curr->next;
        }
    }
    else if ((app->command[cfilter]) == filter_deldir) {
        del_file(&app->cur_dir->list_attr, ".");
        del_file(&app->cur_dir->list_attr, "..");
    }
}

static void del_file(t_list **list, char *removed) {
    t_list *curr = *list;
    // t_list *prev = NULL;
    char *name = ((t_attr *)(curr->data))->file_name;

    if (curr != NULL && mx_strcmp(name, removed) == 0) {
        *list = curr->next;
        mx_free_node_data(curr);
        return;
    }
    // next_name(&curr, &prev, &name, removed);
    // // if (curr == NULL)
    // //     return;
    // // prev->next = curr->next;
    // printf("AAAAAAAAA\n");
}

// static void next_name(t_list **curr, t_list **prev, char **name, char *rm) {
//     while (curr != NULL && mx_strcmp(*name, rm) != 0) {
//         (*prev) = (*curr);
//         (*curr) = (*curr)->next;
//         if ((*curr) != NULL)
//             *name = ((t_attr *)((*curr)->data))->file_name;
//     }
// }
