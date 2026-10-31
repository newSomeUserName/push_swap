

#include "push_swap.h"

void print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n",stack->value);
		stack = stack->prev;
	}
} 


int	main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack stack_b;

	stack_a = parse(argc, argv);
	print_stack(stack_a);
	printf("---------------------------\n");
	sa(&stack_a);
	print_stack(stack_a);
	return (0);
}
