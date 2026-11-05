

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
	t_stack *stack_b;
	stack_b = NULL;

	stack_a = parse(argc, argv);
	if (!stack_a)
		return (0);	
	print_stack(stack_a);
	printf("---------------------------\n");
	pb(&stack_a,&stack_b);
	print_stack(stack_b);
	printf("---------------------------\n");
	print_stack(stack_a);

	return (0);
}
