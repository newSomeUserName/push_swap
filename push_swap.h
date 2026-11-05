

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int		value;
	struct	s_stack *prev;
	struct	s_stack *next;

}	t_stack;

t_stack	*parse(int argc, char *argv[]);
void sa(t_stack **stack);
void sb(t_stack **stack);
void ss(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);
#endif
