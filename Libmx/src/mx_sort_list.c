#include "libmx.h"

t_list *mx_sort_list(t_list *head, bool (*cmp)(void *, void *)) {
    void *t = NULL;

    if (!head)
        return NULL;
    for (t_list *i = head; i->next != NULL; i = i->next) {
        t_list *m = i;
        for (t_list *j = i->next; j != NULL; j = j->next) {
            if (mx_strcmp(m->data, j->data)) {
                m = j;
            }
        }
        t = m->data;
        m->data = i->data;
        i->data = t;
    }
    return head;
}

