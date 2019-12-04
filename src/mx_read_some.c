#include "uls.h"

void mx_read_some(t_App *app) {
    struct stat sb;
    stat(app->dir_path, &sb);
    if ((sb.st_mode & S_IFMT) == S_IFDIR)
        mx_read_dir(app);
    else 
        mx_read_file(app);
}
