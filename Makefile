NAME = uls

NLIB = libmx/libmx.a

HDR = uls.h

SRC = main.c read_dir.c produce_list_attr.c

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

uninstall:
	@cd libmx && make -f Makefile uninstall
	@rm -rf $(NAME)

clean: 
	@cd libmx && make -f Makefile clean
	@rm -rf $(SRC) $(HDR) $(OBJ)
	@rm -rf ./obj
	@rm libmx.h

reinstall: uninstall all
