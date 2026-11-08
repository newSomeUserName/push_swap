NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

PRINTF_DIR	= ft_printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

INCLUDES	= -I$(LIBFT_DIR) -I$(PRINTF_DIR)

NAME_BONUS	= checker

# shared by push_swap and checker (no main here)
COMMON_SRCS	=	push_swap.c		\
				bench.c			\
				strat_picker.c	\
				parser.c		\
				list_utils.c	\
				list_swap.c		\
				list_push.c		\
				list_r.c		\
				list_rr.c		\
				list_swap_np.c	\
				list_r_np.c		\
				list_rr_np.c	\
				algo_utils.c	\
				algo_simple.c	\
				algo_small.c	\
				algo_medium.c	\
				algo_complex.c	\
				algo_adaptive.c	\

SRCS		=	main_push_swap.c

BONUS_SRCS	=	checker.c

COMMON_OBJS	= $(COMMON_SRCS:.c=.o)
OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

LIBS		= -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft

all: $(NAME)

# ftprintf goes before ft because printf uses libft functions
$(NAME): $(LIBFT) $(PRINTF) $(COMMON_OBJS) $(OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(OBJS) $(LIBS) -o $(NAME)

# make bonus builds both programs
bonus: $(NAME) $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(PRINTF) $(COMMON_OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(BONUS_OBJS) $(LIBS) -o $(NAME_BONUS)

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF): FORCE
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(RM) $(COMMON_OBJS) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

FORCE:

.PHONY: all bonus clean fclean re FORCE
