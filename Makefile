NAME = uls

NLIB = libmx/libmx.a

HDR = uls.h

SRC = main.c \
	mx_new_app.c \
	mx_read_dir.c \
	mx_produce_list_attr.c \
	mx_make_attr_array.c \
	mx_apply_filters.c \
	mx_apply_sort.c \
	mx_comparators.c \
	mx_comparators_r.c \
	mx_apply_printmode.c \
	mx_apply_format_time.c \
	mx_print_lines.c \
	mx_clear_flags.c \
	mx_filter_flags.c \
	mx_printable_lines.c \
	mx_read_flags.c \
	mx_make_command.c \
	mx_standart_view.c \
	mx_filter_out_col.c \
	mx_free.c

OBJ = $(SRC:.c=.o)

CFLAG = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install clean

install:
	@cd libmx && make -f Makefile install
	@cp $(addprefix src/, $(SRC)) $(addprefix inc/, $(HDR)) libmx/inc/libmx.h .
	@clang $(CFLAG) -c $(SRC) -I $(HDR) 
	@mkdir obj
	@clang $(CFLAG) $(OBJ) $(NLIB) -o $(NAME)
	@mv $(OBJ) ./obj
	@rm -rf libmx.h $(SRC) $(HDR)

uninstall: clean
	@cd libmx && make -f Makefile uninstall
	@rm -rf $(NAME)

clean: 
	@cd libmx && make -f Makefile clean
	@rm -rf $(OBJ)
	@rm -rf ./obj

reinstall: uninstall install
