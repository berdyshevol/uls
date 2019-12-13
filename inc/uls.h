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

// см. https://developer.apple.com/library/archive/documentation/System/Conceptual/ManPages_iPhoneOS/man2/stat.2.html
typedef struct s_attr {
    char *inode;    // in heap // inode For each file, print the file's file serial number (inode number). -i flag
    char *chmod;    // in heap
    char *user;     // in heap
    char *group;    // in heap
    char *file_name;// -------? we do not know if in heap. Ask Poul
    char *original_name;
    char *fullname; // with path
    blkcnt_t blocks;      /* blocks allocated for file */
    nlink_t links;        /* number or hard links to the file */
    off_t file_size;      /* file size, in bytes */
    time_t a_time;        /* [XSI] Time of last access */
    time_t m_time;
    time_t c_time;
    time_t b_time;
    bool is_dir;
} t_attr;

enum e_attr {
    at_inode,
    at_blocks,
    at_chmod,       
    at_links,
    at_user,
    at_group,
    at_file_size,
    at_time,
    at_file_name,
    at_MAX
};

#define KILOBYTE 1024
#define MEGAOBYTE 1048576
#define GIGABYTE 1073741824

typedef enum {
    off,  // this is for colunms col_blocks, col_owner, col_author, col_group, col_user,
    on,

    filter_nofilter,
    filter_delhidden,
    filter_deldir,
    filter_onlydir,

    sort_nosort, /* -f */
    sort_size,  /* -S */
    sort_ctime, // -tc
    sort_mtime, // -t
    sort_atime,
    sort_btime,
    sort_name,  /* default */

    format_time_full,   // -T
    format_time_short,

    time_type_c,
    time_type_a,    // 
    time_type_m, // default
    time_type_b,

    view_long_format,		/* -l and other options that imply -l */
    view_one_per_line,		/* -1 */
    view_many_per_line,		/* -C */
    view_horizontal,		/* -x */
    view_with_commas,		/* -m */

} e_Command_State;

typedef enum {
    recursion, // -R
    cfilter,
    csort,
    reverse,
    human,
    time_format,
    time_type,  // for output
    cview,
    header_dir,  // for -R
    header_total, // for -l
    numerically,    // -n
    kilobytes,      // -k
    col_inode,      // -i
    col_blocks,     // -s
    col_user,      // -g
    col_group,      // -o
    MAX_COMMANDS
} e_Command;

typedef enum e_flag { // 33 flags:
minus,
dog, //  -@  -- display extended attribute keys and sizes in long (-l) output
one, //  +1  -- single column output
l, //  +l  -- bacik case..
A, //  +A  -- list all except . and ..
B, //  -B  -- print octal escapes for control characters 
C, //  +C  -- list entries in columns sorted vertically
F, //  -F  -- append file type indicators
H, //  -H  -- follow symlinks on the command line
L, //  -L  -- list referenced file for sym link
P, //  -P  -- do not follow symlinks
R, //  +R  -- list subdirectories recursively
S, //  +S  -- sort by size
T, //  +T  -- show complete time information
U,
a, //  +a  -- list entries starting with .
b, //  -b  -- as -B, but use C escape codes whenever possible
c, //  +c  -- status change time
d, //  -d  -- list directory entries instead of contents
f, //  +f  -- output is not sorted
g, //  +g  -- long listing but without owner information
h, //  +h  -- print sizes in human readable form
i, //  +i  -- print file inode numbers
k, //  +k  -- print sizes of 1k
m, //  +m  -- comma separated
n, //  +n  -- numeric uid, gid
o, //  -o  -- display file flags
p, //  -p  -- append file type indicators for directory
q, //  -q  -- hide control chars
r, //  +r  -- reverse sort order
s, //  +s  -- display size of each file in blocks
t, //  +t  -- sort by modification time
u, //  +u  -- access time
w, //  -w  -- print raw characters
x, //  -x  -- sort horizontally
size, // number of flags
} t_flag;

typedef struct {
    t_list *list_attr;  // in heap
    t_list *raw_lines;  // in heap
    char *dir_path; // in heap
    bool is_dir;
    int *command;   // in heap
    int *al; // pointer to aligning
    bool print_permission_denied;
    bool new_line_needed;
} t_lfa; // list of file_attr;

typedef struct {
    int *al; // attributs for aligning
    int *flags;
    bool is_any_flags;
    int command[MAX_COMMANDS];
    t_list *args_error;
    t_list *args_files;
    t_list *args_directories;
    //bool currentdir;

} t_App;

t_App *mx_new_app(void);
void mx_clear_flags(int *flags);
void mx_filter_flags(char *argv, int *fl);
void mx_read_flags(char **s, int argc, t_App *app);
void mx_make_command(t_App *app);
void mx_read_args(int argc, char *argv[], t_App *app);
void mx_print_args_error(t_App *app);
void mx_print_args_file(t_App *app);
t_lfa *mx_new_lfa(t_App *app, char *current_dir);
void mx_free_lfa(t_lfa **lfa);
void mx_print_args_directories(t_App *app);


//void mx_print_one_directory(t_lfa *lfa, t_App *app);
void mx_print_one_directory(char *name, t_App *app);
void mx_standart_view(t_list *list);
void mx_non_standart(t_list *list);
//void mx_produce_list_attr(t_lfa *lfa);
t_lfa *mx_produce_list_attr(char *dirname, t_App *app);
////  void mx_produce_attr(t_App *app);
t_attr *mx_make_attr_struct(char *fileName, t_lfa *lfa);
void mx_apply(t_lfa *lfa);
void mx_apply_without_printing(t_lfa *lfa);
void mx_apply_sort(t_lfa *lfa);
//void mx_apply_filters(t_lfa *lfa);
bool mx_apply_filters_ok(char *filename, t_lfa *lfa);
void mx_apply_printmode(t_lfa *lfa);
void mx_apply_format_time(t_list *row, t_list *cur, t_lfa *lfa);
bool mx_is_switched_off(int i, t_lfa *lfa);
char *format_size(off_t size, t_lfa *lfa);

char *get_dir_path();

// errors
void mx_print_permission_denied(char *dirname);

// print
void mx_header_dir(t_lfa *lfa);
void mx_header_total(t_lfa *lfa);
void mx_print_lines(t_lfa *lfa);
t_list *mx_printable_lines(t_list *head, int *a, t_lfa *lfa);
void mx_check_eror_flag(char *s);

// free functions
void mx_free_node_data(t_list *node);


/* comparators for sorting commamd*/
bool mx_cmp_size(void *data1, void *data2);
bool mx_cmp_c_time(void *data1, void *data2);
bool mx_cmp_name(void *data1, void *data2);
bool mx_cmp_m_time(void *data1, void *data2);
bool mx_cmp_a_time(void *data1, void *data2);
bool mx_cmp_b_time(void *data1, void *data2);
bool mx_cmp_size_r(void *data1, void *data2);
bool mx_cmp_c_time_r(void *data1, void *data2);
bool mx_cmp_name_r(void *data1, void *data2);
bool mx_cmp_m_time_r(void *data1, void *data2);
bool mx_cmp_a_time_r(void *data1, void *data2);
bool mx_cmp_b_time_r(void *data1, void *data2);

// utils
bool mx_is_dot_dotdot(char *name);
//t_attr *mx_getstruct(t_list *node);

//helping function   - to be deleted
void print_raw_lines(t_list *head);
void print_attr_list(t_list *head);

#endif

