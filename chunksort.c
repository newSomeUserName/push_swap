
#include "push_swap.h"

static t_node *convert_to_rank(t_node *stack_a)
{
    int     count;
    t_node  *current;
    t_node  *next;
    t_node  *rank_stack;
    t_node  *new;
    
    rank_stack = NULL;
    current = stack_a;
    while (current)
    {
        count = 0;
        next = stack_a;
        while (next)
        {
            if ((current)->value > next->value)
                count++;
            next = next->next;
        }
        if (!(new = node_new(count)))
            return (stack_free(&rank_stack), NULL);
        stack_add_back(&rank_stack,new);
        current = current->next;
    }
    return (rank_stack);
}

static int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i <= nb / i)
		i++;
	return (i - 1);
}
static void replace_all_to_b_stack(t_node **rank_stack, t_node **stack_b)
{
    int i;
    int offset;
    
    i = 0;
    offset = ft_sqrt(stack_size(*rank_stack)) * 15 / 10;
    while (*rank_stack)
    {
        if ((*rank_stack)->value <= i)
        {
            pb(rank_stack,stack_b);
            rb(stack_b);
            i++;
        }
        else if((*rank_stack)->value <= i + offset)
        {
            pb(rank_stack,stack_b);
            i++;
        }
        else
            ra(rank_stack);
    }
}
static int	get_position(t_node *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

static void butterfly_sort(t_node **rank_stack, t_node **stack_b)
{
    int stack_len;
    int pos;
    replace_all_to_b_stack(rank_stack,stack_b);
    while (*stack_b)
	{
		stack_len = stack_size(*stack_b);
		pos = get_position(*stack_b, stack_len - 1);
		if (pos <= stack_len / 2)
		{
			while (pos-- > 0)
				rb(stack_b);
		}
		else
		{
			while (pos++ < stack_len)
				rrb(stack_b);
		}
		pa(rank_stack, stack_b);
	}
}

void chunk_sort(t_node **stack_a, t_node **stack_b)
{
    t_node *rank_stack;

    rank_stack = convert_to_rank(*stack_a);
    if (!rank_stack)
    {
        stack_free(stack_a);
        stack_free(stack_b);
        exit(1);
    }
    butterfly_sort(&rank_stack, stack_b);
    stack_free(stack_a);
    stack_free(stack_b);
}