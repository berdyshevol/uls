#include "uls.h"

static t_list *all_max_len(t_list *head);
static int *max_len_col(t_list *head, int num);
static char *aline(char *s, int max_len, int aline);

t_list *mx_printable_lines(t_list *head, int *a) {
    t_list *max_len = all_max_len(head);
    t_list *ptr = NULL;
    t_list *res = NULL;
    t_list *max = NULL;
    char *str = NULL;
    char *tmp = NULL;
    char *word = NULL;

    for(; head != NULL; head = head->next, str = NULL) { 
        ptr = head->data;
        max = max_len;
        for (int i = 0; ptr != NULL; i++, ptr = ptr->next, max = max->next) {
            tmp = str;
            word = aline(ptr->data, *((int *)(max->data)), a[i]);
            str = mx_strjoin(str, word);
            free(tmp);
            free(word);
        }
        mx_push_back(&res, mx_strdup(str));
        free(str);
    }
    for (max = max_len; max != NULL; max = max->next) {
        free(max->data);
        mx_pop_front(&max_len);
    }
    return res;
}

static t_list *all_max_len(t_list *head) {
    t_list *ptr = head->data;
    t_list *res = NULL;
    int num = 0;

    for(; ptr != NULL; num++, ptr = ptr->next);
    for(int i = 0; i < num; i++)
        mx_push_back(&res, max_len_col(head, i));
    return res;
}

static int *max_len_col(t_list *head, int num) { //num is number of colum
    int *max = malloc(sizeof(int));
    t_list *ptr = head;
    t_list *col = NULL;
    int tmp = 0;
    
    for (; ptr != NULL; ptr = ptr->next) {
        col = ptr->data;
        for(int n = 0; n < num; n++, col = col->next);
        tmp = mx_strlen((char *)(col->data));
        *max = (tmp > *max) ? tmp : *max;
    }
    return max;
}

static char *aline(char *s, int max_len, int aline) {
    char *res = NULL;
    int  len = mx_strlen(s);
    int space = max_len - len;

    if (aline < 0) {
        res = mx_strnew(max_len + (-aline));
        mx_strcpy(res, s);
        for (int i = len; i < (max_len + (-aline)); res[i] = ' ', i++);
    } else if (aline > 0) {
        res = mx_strnew(max_len + aline);
        for (int i = 0; i < space; res[i] = ' ', i++);
        mx_strcpy(&res[space], s);
        for (int i = max_len; i < (max_len + aline); res[i] = ' ', i++);
    } else
        res = mx_strdup(s);
    return res;
}
