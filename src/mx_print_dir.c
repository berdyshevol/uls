#include "uls.h"

void print_attr_struc(t_attr *attr_array) {
		printf("%llu\t", attr_array->blocks);
		printf("%s\t", attr_array->chmod);
		printf("%d\t", attr_array->links);
		printf("%s\t", (char *)attr_array->user);
		printf("%s\t", (char *)attr_array->group);
        printf("%llu\t", attr_array->file_size);
		printf("%lu\t", attr_array->a_time);
		printf("%lu\t", attr_array->m_time);
		//printf("%s\t", attr_array->time);
		printf("%s\t", attr_array->file_name);
	printf("\n");
}

void print_attr_list(t_list *head) {
    printf("Print list of files attributes\nHEAD\nV\n");
    for (t_list *cur = head; cur != NULL; cur = cur->next) {
        print_attr_struc((t_attr *)(cur->data));
		//printf("%s\n", ((t_attr *)(cur->data))->file_name);
    }
}

#include "uls.h"

// void print_attr_struc(t_attr *attr_array) {
// 		printf("%llu\t", attr_array->blocks);
// 		printf("%s\t", attr_array->chmod);
// 		printf("%d\t", attr_array->links);
// 		printf("%s\t", (char *)attr_array->user);
// 		printf("%s\t", (char *)attr_array->group);
//         printf("%llu\t", attr_array->file_size);
// 		printf("%lu\t", attr_array->a_time);
// 		printf("%lu\t", attr_array->m_time);
// 		printf("%s\t", attr_array->time);
// 		printf("%s\t", attr_array->file_name);
// 	printf("\n");
// }

void print_list_of_str(t_list *head) {
	for (t_list *cur = head; cur != NULL; cur = cur->next) {
		printf("%s ", (char *)(cur->data));
	}
	printf("\n");
}

void print_raw_lines(t_list *head) {
    for (t_list *cur = head; cur != NULL; cur = cur->next) {
        print_list_of_str((t_list *)(cur->data));
		//printf("%s\n", ((t_attr *)(cur->data))->file_name);
    }
}
