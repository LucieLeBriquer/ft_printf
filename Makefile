CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
NAME		= libftprintf.a
INCS		= ft_print.h
INCS_DIR	= includes
LIB			= includes/libft.a

SRCS		= ft_printf.c \
			parse/errors.c \
			parse/params.c \
			print/print_0chr.c \
			print/print_1str.c \
			print/print_2ptr.c \
			print/print_3dbl.c \
			print/print_4int.c \
			print/print_5uns.c \
			print/print_6hex.c \
			print/print_7heX.c \
			print/print.c \
			utils/useful.c \
			utils/tohelp.c

OBJS		= $(SRCS:.c=.o)

%.o			: %.c
			$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

all			: $(NAME)

$(NAME)		: $(OBJS)
			make -C ./libft
			cp libft/libft.* includes/
			ar rcs libftprintf.a $(OBJS)
		
test		: all
			$(CC) -I$(INCS_DIR) main.c $(NAME) $(LIB) -o tests

clean:
			make clean -C ./libft
			$(RM) $(OBJS)

fclean		: clean
			$(RM) $(NAME) $(LIB) tests

re			: fclean all

.PHONY		: all clean fclean re
