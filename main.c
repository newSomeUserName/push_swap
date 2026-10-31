

#include "push_swap.h"


t_stack *create_node(int value)
{
	t_stack *stack_node;

	stack_node = malloc(sizeof(t_stack));
	if (!stack_node)
		return (NULL);
	stack_node->value = value;
	stack_node->next = NULL;
	stack_node->prev = NULL;
	return (stack_node);
}
void *add_back(t_stack **head, t_stack *node)
{
	node->prev = *head;
	(*head)->next = node;
	*head = node;
}
void *clean_stack(t_stack **head)
{
	t_stack *prev;
	while (*head)
	{
		prev = (*head)->prev;
		free(*head);
		*head = prev;
	}
	*head = NULL;
	return (NULL);
}

t_stack	*parse(int argc, char *argv[])
{
	int	counter;
	t_stack *node;
	t_stack *head;
	
	counter = 1;
	if (argc < 2)
		return (NULL);
	while (counter < argc)
	{
		if (counter == 1)
		{
			head = create_node(atoi(argv[counter]));
			if (!head)
				return (NULL);		
		}
		else
		{
			node = create_node(atoi(argv[counter]));
			if (!node)
				return (clean_stack(&head));
			add_back(&head, node);
		}
		counter++;
	}
	return (head);
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack stack_b;

	stack_a = parse(argc, argv);
	while (stack_a)
	{
		printf("%d\n",stack_a->value);
		stack_a = stack_a->prev;
	}
	
	return (0);
}
