#include "uls.h"

static void do_view_long_format(t_lfa *lfa);
static void do_one_per_line(t_lfa *lfa, t_App *app);
static void do_many_per_line(t_lfa *lfa, t_App *app);
static void choose_mode(t_lfa *lfa, t_App *app);

void mx_apply_printmode(t_lfa *lfa, t_App *app) {
    static bool has_printed_anithing = false;

    lfa->new_line_needed = has_printed_anithing;
    if (app->first_dir_name_needed)
        lfa->command[header_dir] = on;
    mx_header_dir(lfa);
    if (lfa->list_attr == NULL) return;
    choose_mode(lfa, app);
    has_printed_anithing = true;
}

static void choose_mode(t_lfa *lfa, t_App *app) {
    switch (lfa->command[cview]) {
        case view_long_format:
            do_view_long_format(lfa);
            break;
        case view_one_per_line:
            do_one_per_line(lfa, app);
            break;
        case view_many_per_line:
            do_many_per_line(lfa, app);
            break;
        case view_with_commas:
            mx_std_and_pipe(lfa, app);
            break;
    }
}

static void do_view_long_format(t_lfa *lfa) {
    mx_apply_printmode_flag_l(lfa);
    mx_header_total(lfa);
    mx_print_lines(lfa);
}

static void do_one_per_line(t_lfa *lfa, t_App *app) {
    mx_header_total(lfa);
    mx_std_and_pipe(lfa, app);
}

static void do_many_per_line(t_lfa *lfa, t_App *app) {
    mx_header_total(lfa);
    mx_std_and_pipe(lfa, app);
}

