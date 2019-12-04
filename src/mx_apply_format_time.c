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
    //parse(ctime(&(attr->m_time), &day, &mon, &hour, &min, &sec, &year);
  
    time_t time;
    switch (app->command[time_type]) {
        case time_type_c:
            time = ((t_attr *)(cur->data))->c_time;
            break;
        case time_type_a:  // 
            time = ((t_attr *)(cur->data))->a_time;
            break;
        case time_type_m:
            time = ((t_attr *)(cur->data))->m_time;
            break;  
    }

    char *s = NULL;
    switch (app->command[time_format]) {
        case format_time_full:
            s = mx_strdup(ctime(&(time)));
            s[mx_strlen(s)-1] = '\0';
            break;
        case format_time_short:
            s = mx_strdup("no_time_format");
            break;
    }
    
    //exit(1);
    // if (app->command[cformat_size] == format_size_noth) {
    //    char *s = mx_strdup(ctime(&(((t_attr *)(cur->data))->m_time)));
    //     s[mx_strlen(s)-1] = '\0';
    //     mx_push_back(&row, (void *)s);
    //     return;
    // }
    // else if (app->command[cformat_size] == format_size_h) {
    //     // TODO: time in human way
    // }
    mx_push_back(&row, (void *)s);
}

