#include "uls.h"
/* здесь нежно распарсить на день, месяц ... год. Потом push с raw_str*/

// parse(char *time, char **day, char **mon, char **hour, char **min, char **sec, char **year) {
//     int i = mx_get_char_index(time, " ");

// }

void mx_apply_format_time(t_list *row, t_list *cur, t_App *app) {
    // char *day = NULL;
    // char *mon = NULL;
    // char *hour = NULL;
    // char *min = NULL;
    // char *sec = NULL;
    // char *year = NULL;
    // parse(ctime(&(attr->m_time), &day, &mon, &hour, &min, &sec, &year);
    
    if (app->command[cformat_size] == format_size_noth) {
        char *s = mx_strdup(ctime(&(((t_attr *)(cur->data))->m_time)));
        s[mx_strlen(s)-1] = '\0';
        mx_push_back(&row, (void *)s);
        return;
    }
    else if (app->command[cformat_size] == format_size_h) {
        // TODO: time in human way
    }
    mx_push_back(&row, (void *)mx_strdup("no_time_format"));
}

