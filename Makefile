##
## EPITECH PROJECT, 2023
## undefined
## File description:
## Makefile to compile files with the lib.
## Makefile
##

SRC	=	$(wildcard *.c)

BIN_NAME	=	setting_up

all:	compile_lib compile

compile_lib:
	make re -C lib/my

compile:	$(OBJ)
	gcc $(SRC) -L. -lmy -o $(BIN_NAME)

clean:
	rm -f $(OBJ)
	make clean -C lib/my

fclean:	clean
	rm -f $(BIN_NAME)
	make fclean -C lib/my

re:	fclean all
