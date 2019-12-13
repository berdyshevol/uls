#include "uls.h"

void mx_clear_flags(int *flags) {
	for (int i = 0; i < size; i++)
		flags[i] = 0;
}
