#include "uls.h"

void print_total(t_App *app) {
    unsigned long total = 0;

    app->command[cheader]
}

void print_dir_name(t_App *app) {

}

void mx_apply_header(t_App *app) {
    switch (app->command[cheader]) {
        case header_no:
            break;
        case header_total:
            print_total(app);
            break;
        case header_dir_total:
            print_dir_name(app);
            print_total(app);
            break;
    }
}



