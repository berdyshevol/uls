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

// typedef enum e_attr {
//     attr_blocks,
//     attr_chmod,
//     attr_links,
//     attr_user,
//     attr_group,
//     attr_file_size,
//     attr_a_time,
//     attr_m_time,
//     attr_c_time,
//     attr_file_name,
//     MAX_ATTR
// } t_attr;

// см. https://developer.apple.com/library/archive/documentation/System/Conceptual/ManPages_iPhoneOS/man2/stat.2.html
typedef struct s_attr {
    blkcnt_t blocks;      /* blocks allocated for file */
    char *chmod;       
    nlink_t links;        /* number or hard links to the file */
    char *user;
    char *group;
    off_t file_size;      /* file size, in bytes */
    time_t a_time;        /* [XSI] Time of last access */
    time_t m_time;
    time_t c_time;
    char *file_name;
} t_attr;

//typedef void *t_attr_array[MAX_ATTR];


typedef struct {
    t_list *list_attr;
    t_list *raw_lines;
    DIR *current_DIR;
} t_CD;

typedef enum {
    off,
    on,

    filter_nofilter,
    filter_delhidden,
    filter_deldir,
    filter_onlydir,

    sort_nosort, /* -U */
    sort_size,  /* -S */
    sort_ctime,
    sort_atime,
    sort_mtime,
    sort_name,  /* default */

    format_size_noth,
    format_size_h,

    format_time_full,
    format_time_short,

    view_long_format,		/* -l and other options that imply -l */
    view_one_per_line,		/* -1 */
    view_many_per_line,		/* -C */
    view_horizontal,		/* -x */
    view_with_commas,		/* -m */

    header_no,
    header_total,
    header_dir,
} e_Command_State;

typedef enum {
    cfilter,
    csort,
    cformat_size,
    cformat_time,
    cview,
    cheader,
    col_blocks,
    col_owner,
    col_author,
    col_group,
    col_user,
    MAX_COMMANDS
} e_Command;

typedef enum e_flag { // 33 flags:
minus,
dog, //  -@  -- display extended attribute keys and sizes in long (-l) output 
one, //  -1  -- single column output
l, //  -l  -- bacik case..
A, //  -A  -- list all except . and ..
B, //  -B  -- print octal escapes for control characters
C, //  -C  -- list entries in columns sorted vertically
F, //  -F  -- append file type indicators
H, //  -H  -- follow symlinks on the command line
L, //  -L  -- list referenced file for sym link
P, //  -P  -- do not follow symlinks
R, //  -R  -- list subdirectories recursively
S, //  -S  -- sort by size
T, //  -T  -- show complete time information
a, //  -a  -- list entries starting with .
b, //  -b  -- as -B, but use C escape codes whenever possible
c, //  -c  -- status change time
d, //  -d  -- list directory entries instead of contents
f, //  -f  -- output is not sorted
g, //  -g  -- long listing but without owner information
h, //  -h  -- print sizes in human readable form
i, //  -i  -- print file inode numbers
k, //  -k  -- print sizes of 1k
m, //  -m  -- comma separated
n, //  -n  -- numeric uid, gid
o, //  -o  -- display file flags
p, //  -p  -- append file type indicators for directory
q, //  -q  -- hide control chars
r, //  -r  -- reverse sort order
s, //  -s  -- display size of each file in blocks
t, //  -t  -- sort by modification time
u, //  -u  -- access time
w, //  -w  -- print raw characters
x, //  -x  -- sort horizontally
size, // number of flags
} t_flag;

typedef struct {
    int *al; // attributs for aligning
    int *flags;
    int command[MAX_COMMANDS];
    char *dir_path;
    t_CD *cur_dir; // будет с каждой новой дерикторией меняться здесь будут лики
} t_App;

void mx_make_command(t_App *app);
void mx_read_dir(t_App *app);
void mx_produce_list_attr(t_App *app);
void mx_apply_sort(t_App *app);
void mx_apply_filters(t_App *app);
void mx_apply_printmode(t_App *app);
void mx_apply_format_time(t_list *row, t_list *cur, t_App *app);

void mx_clear_flags(int *flags);
void mx_filter_flags(char *argv, int *fl);
void mx_read_flags(char **s, int argc, int *fl, char **dir_path);
char *get_dir_path();
void mx_print_lines(t_App *app);
t_list *mx_printable_lines(t_list *head, int *a);


/* comparators for sorting commamd*/
bool cmp_size(void *data1, void *data2);
bool cmp_c_time(void *data1, void *data2);
bool cmp_a_time(void *data1, void *data2);
bool cmp_name(void *data1, void *data2);
bool cmp_m_time(void *data1, void *data2);

//helping function   - to be deleted
void print_raw_lines(t_list *head);

#endif

