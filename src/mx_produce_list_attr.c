#include "uls.h"

void mx_produce_list_attr(t_lfa *lfa) {
    DIR *d = opendir(lfa->dir_path);
    //lfa->current_DIR = d;
	struct dirent *entry;
	lfa->is_dir = true;
	while ((entry = readdir(d)) != NULL)
		mx_push_back(&(lfa->list_attr),
			(void *)mx_make_attr_struct((entry->d_name), lfa));
	
	closedir(d);
}
