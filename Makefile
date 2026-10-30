NAME = exe
MAIN_SRC = main.c

SRCS = push_swap.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS) $(MAIN_SRC)
	cc $(MAIN_SRC) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	cc -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

.PHONY: all clean
