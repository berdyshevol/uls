#ifndef ULS_H
#define ULS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <dirent.h>
#include <errno.h>

#include "libmx.h"

typedef enum e_attr {
    attr_blocks,
    attr_chmod,
    attr_links,
    attr_user,
    attr_group,
    attr_file_size,
    attr_a_time,
    attr_m_time,
    attr_c_time,
    attr_file_name,
    MAX_ATTR
} t_attr;

//typedef void *t_attr_array[MAX_ATTR];

typedef struct {
    t_list *list_attr;
    t_list *raw_lines;
    DIR *current_DIR;
} t_CD;

typedef enum {
    filter_nofilter,
    filter_removehidden,
    filter_all_exept_current,

    sort_nosort,
    sort_size,
    sort_ctime,
    sort_atime,
    sort_mtime,

    format_comma,
    format_nocomma,

    format_size_noth,
    format_size_h,

    format_time_full,
    format_time_short,

    view_l,
    view_std,
    view_1,

    header_total,
    header_dir

} e_Command_State;

typedef enum {
    cfilter,
    csort,
    ccolumns,
    comma,
    cformat_size,
    cformat_time,
    cview,
    cheader,
    MAX_COMMANDS
} e_Command;

typedef struct {
    int *al; // attributs for aligning
    int *flags;
    int *command[MAX_COMMANDS];
    t_CD *cur_dir; // будет с каждой новой дерикторией меняться здесь будут лики
} t_App;

void read_dir(t_App *app);
void produce_list_attr(t_App *app);

#endif

