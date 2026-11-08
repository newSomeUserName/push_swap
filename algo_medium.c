/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 18:00:00 by jlucotte          #+#    #+#             */
/*   Updated: 2026/11/05 18:00:00 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	replace_all_to_b_stack(t_stack **rank_stack, t_stack **stack_b)
{
	int	i;
	int	offset;

	i = 0;
	offset = ft_sqrt(count_node(*rank_stack)) * 15 / 10;
	while (*rank_stack)
	{
		if ((*rank_stack)->rank <= i)
		{
			pb(rank_stack, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*rank_stack)->rank <= i + offset)
		{
			pb(rank_stack, stack_b);
			i++;
		}
		else
			ra(rank_stack);
	}
}

static int	get_position(t_stack *stack, int rank)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->rank == rank)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

static void	butterfly_sort(t_stack **rank_stack, t_stack **stack_b)
{
	int	stack_len;
	int	pos;

	replace_all_to_b_stack(rank_stack, stack_b);
	while (*stack_b)
	{
		stack_len = count_node(*stack_b);
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

void	medium_sort(t_stack **stack_a, t_stack **stack_b)
{
	assign_rank(stack_a);
	butterfly_sort(stack_a, stack_b);
}
