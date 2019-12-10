#include "libmx.h"

void mx_pop_front(t_list **head) {
    t_list *temp = NULL;
    t_list *tmp = NULL;

    if (*head != NULL || head != NULL) {
        if ((*head)->next == NULL) {
            (*head)->data = NULL;
            free(*head);
            *head = NULL;
        }
        else {
            temp = *head;
            tmp = temp->next;
            temp->data = NULL;
            free(temp);
            temp = NULL;

            *head = tmp;
        }
    }
}
