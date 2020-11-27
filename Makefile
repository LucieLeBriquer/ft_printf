CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
NAME		= libftprintf.a
INCS		= ft_print.h
INCS_DIR	= includes

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
			utils/tohelp.c \
			utils/ft_atoi.c \
			utils/ft_isdigit.c \
			utils/ft_itoa.c \
			utils/ft_putstr.c \
			utils/ft_strlen.c \
			utils/ft_utoa.c \
			utils/ft_utox.c \
			utils/ft_utoxx.c

OBJS		= $(SRCS:.c=.o)

%.o			: %.c
			$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

all			: $(NAME)

$(NAME)		: $(OBJS)
			ar rcs $(NAME) $(OBJS)
		
test		: all
			$(CC) -I$(INCS_DIR) main.c $(NAME) -o tests
			./tests

clean:
			$(RM) $(OBJS)

fclean		: clean
			$(RM) $(NAME) $(LIB) tests

re			: fclean all

.PHONY		: all clean fclean re
