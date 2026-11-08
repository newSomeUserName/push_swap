NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

# libft lives next to this folder, in push_swap/libft
LIBFT_DIR	= ../libft

SRCS		=	ft_printf.c		\
				handlers.c		\
				check_n_store.c	\
				init.c			\
				add_flags.c		\
				number_utils.c	\
				print_nbr.c		\
				printer.c		\
				ft_putstr.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
