

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	int		value;
	struct	s_stack *prev;
	struct	s_stack *next;

}	t_stack;

void prints();

#endif
