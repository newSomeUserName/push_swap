

#include "push_swap.h"


t_stack create_node(int value)
{
	t_stack stack_node;

	stack_node.value = value;
	stack_node.next = NULL;
	stack_node.prev = NULL;
	return (stack_node);
}

int	parse(int argc, char *argv[])
{
	int	counter;

	counter = 1;
	if (argc < 2)
		return (-1);
	while (counter < argc)
	{
		create_node(argv[counter])
	}


	atoi(argv[0]);
	return (0);
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_stack stack_a;
	t_stack stack_b;

	printf("%d\n", argc);

	// prints();
	// prints();
	return (0);
}
