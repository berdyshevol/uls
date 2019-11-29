#include "uls.h"

static char at_plus_space(char *file) {
	acl_t acl = acl_get_file(file, ACL_TYPE_EXTENDED);
    ssize_t xattr = listxattr(file, NULL, 0, XATTR_NOFOLLOW);
    char chr;

    if (xattr > 0)
        chr = '@';
    else if (acl != NULL)
        chr = '+';
    else
        chr = ' ';

    return chr;
}

static char *eleven_chars_code(struct stat sb, char *file) {
	char *res = mx_strnew(11);
	res[0] = S_ISBLK(sb.st_mode) ? 'b' : \
			 S_ISCHR(sb.st_mode) ? 'c' : \
			 S_ISDIR(sb.st_mode) ? 'd' : \
			 S_ISSOCK(sb.st_mode) ? 's' : \
			 S_ISFIFO(sb.st_mode) ? 'p' : \
			 S_ISLNK(sb.st_mode) ? 'l' : '-';
	res[1] = (S_IRUSR & sb.st_mode) ? 'r' : '-';
	res[2] = (S_IWUSR & sb.st_mode) ? 'w' : '-';
	res[3] = (S_IXUSR & sb.st_mode) ? 'x' : '-';
	res[4] = (S_IRGRP & sb.st_mode) ? 'r' : '-';
	res[5] = (S_IWGRP & sb.st_mode) ? 'w' : '-';
	res[6] = (S_IXGRP & sb.st_mode) ? 'x' : '-';
	res[7] = (S_IROTH & sb.st_mode) ? 'r' : '-';
	res[8] = (S_IWOTH & sb.st_mode) ? 'w' : '-';
	res[9] = (S_ISTXT & sb.st_mode) ? 't' : \
			 (S_IXOTH & sb.st_mode) ? 'x' : '-';
	res[10] = at_plus_space(file);
	return res;
}

char *get_user(uid_t uid)
{
    struct passwd *pws;
    pws = getpwuid(uid);
        return pws->pw_name;
}

char *get_group(gid_t gid)
{
    struct group *g;
	if ((g = getgrgid(gid)) != NULL)
    	return g->gr_name;
	else
    	return mx_itoa(gid);
}

char *get_name(struct stat sb,  char *file) {
	char link_read[255];
	ssize_t bytes_read;
	char *res = NULL, *tmp = NULL;
	if(S_ISLNK(sb.st_mode)){
		//printf("@\033[35m%s ", file);
		//printf("\033[37m");
		tmp = mx_strjoin(file, " -> ");
	    bytes_read = readlink(file, link_read, 254);
		link_read[bytes_read] = '\0';
		res = mx_strjoin(tmp, link_read);
		mx_strdel(&tmp);
	}
	else if((S_IXUSR & sb.st_mode) || (S_IXGRP & sb.st_mode) || (S_IXOTH & sb.st_mode))
		res = mx_strdup(file); //printf("\033[31m%s\033[37m\n", file);
	else if(S_ISFIFO(sb.st_mode))
		res = mx_strdup(file); //printf("\033[33m%s\033[37m\n", file);
	else 
		res = mx_strdup(file); //printf("%s\n", file);
	return res;
}

static void *make_attr_array(char *name) {
	struct stat sb;
	stat(name, &sb);
    void **attr_array = malloc(sizeof(void *) * MAX_ATTR);
    attr_array[attr_blocks] = &sb.st_blocks;
    attr_array[attr_chmod] = eleven_chars_code(sb, name); // -rw-r--r--@ 
    attr_array[attr_links] = &sb.st_nlink; // 1
	attr_array[attr_user] = get_user(sb.st_uid); // psymonov
	attr_array[attr_group] = get_group(sb.st_gid); // 4242
    attr_array[attr_file_size] = &sb.st_size; // 623
    //time_for_lflag(sb, arr); // Nov 18 17:33
    attr_array[attr_a_time] = &sb.st_atimespec;
    attr_array[attr_m_time] = &sb.st_mtimespec;
    attr_array[attr_c_time] = &sb.st_ctimespec;
	attr_array[attr_file_name] = get_name(sb, name); // Makefile
	return attr_array;
}

void produce_list_attr(t_App *app) {
    struct dirent *entry;
	DIR *d = app->cur_dir->current_DIR;
	while ((entry = readdir(d)) != NULL){
			mx_push_back(&(app->cur_dir->list_attr), make_attr_array(entry->d_name));
	}
    //mx_del_strarr(&listAttr->data);
	//printf("%lld", sb.st_blocks); // - печатает  Total blocks size
}

