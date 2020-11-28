CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
NAME		= libftprintf.a
INCS		= ft_printf.h
INCS_DIR	= .

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
			print/print_7hexx.c \
			print/print_8pct.c \
			print/print_9oct.c \
			print/fun_print_str.c \
			print/fun_print_int.c \
			print/fun_print_int_bis.c \
			print/print.c \
			utils/utils_str.c \
			utils/utils_int.c \
			utils/nbtostr.c \
			utils/nbtostr2.c

OBJS		= $(SRCS:.c=.o)

%.o			: %.c
			$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

all			: $(NAME)

$(NAME)		: $(OBJS) $(INCS)
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
