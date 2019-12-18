#include "uls.h"

static char *stat_path(char *fileName, char *dirName);
static void fill_struct1(struct stat sb, char *fullname,
                         t_attr *attr_struct, t_lfa *lfa);
static void fill_struct2(struct stat sb, char *fullname,
                         t_attr *attr_struct);

t_attr *mx_make_attr_struct(char *fileName, t_lfa *lfa) {
    struct stat sb;
    char *fullname = NULL;

    fullname = stat_path(fileName, lfa->dir_path);
	lstat(fullname, &sb);
    t_attr *attr_struct = malloc(sizeof(t_attr));
    fill_struct1(sb, fullname, attr_struct, lfa);
    attr_struct->file_name = mx_get_name(sb, fileName, fullname, lfa);
    attr_struct->original_name = mx_strdup(fileName);
    attr_struct->a_time = sb.st_atime;
    attr_struct->m_time = sb.st_mtime;
    attr_struct->c_time =  sb.st_ctime;
    attr_struct->b_time = sb.st_birthtimespec.tv_sec;
    fill_struct2(sb, fullname, attr_struct);
    return attr_struct;
}

static char *stat_path(char *fileName, char *dirName) {
    char *res = NULL;

    if (mx_strcmp(fileName, "/") == 0 || mx_strcmp(dirName, "") == 0) {
        res = mx_strdup(fileName);
    }
    else {
        char *tmp = NULL;
        tmp = mx_strjoin(dirName, "/");
        res = mx_strjoin(tmp, fileName);
        mx_strdel(&tmp);
    }
    return res;
}

static void fill_struct1(struct stat sb, char *fullname,
                         t_attr *attr_struct, t_lfa *lfa) {
    attr_struct->inode = mx_itoa(sb.st_ino);
    if (lfa->command[kilobytes] == off) {
        attr_struct->blocks = sb.st_blocks;
    }
    else if (lfa->command[kilobytes] == on)
        attr_struct->blocks = sb.st_blocks % 2 == 0 ? sb.st_blocks / 2
                                                    : sb.st_blocks / 2 + 1;
    attr_struct->chmod = mx_eleven_chars_code(sb, fullname);
    attr_struct->links = sb.st_nlink;
    if (lfa->command[numerically] == off) {
        attr_struct->user = mx_get_user(sb.st_uid);
        attr_struct->group = mx_get_group(sb.st_gid);
    }
    else if (lfa->command[numerically] == on){
        attr_struct->user = mx_itoa(sb.st_uid);
        attr_struct->group = mx_itoa(sb.st_gid);
    }
}

static void fill_struct2(struct stat sb, char *fullname,
                         t_attr *attr_struct) {
    attr_struct->file_size = sb.st_size;
    attr_struct->fullname = fullname;
    if ((sb.st_mode & S_IFMT) == S_IFDIR)
        attr_struct->is_dir = true;
    else
        attr_struct->is_dir = false;
    if (S_ISBLK(sb.st_mode) || S_ISCHR(sb.st_mode)) {
        attr_struct->c_or_b = true;
        attr_struct->major_num = major(sb.st_rdev);
        attr_struct->minor_num = minor(sb.st_rdev);
    }
    else {
        attr_struct->c_or_b = false;
        attr_struct->major_num = 0;
        attr_struct->minor_num = 0;
    }
}

