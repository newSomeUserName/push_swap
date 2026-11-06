/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:38:39 by jlucotte          #+#    #+#             */
/*   Updated: 2026/11/06 18:34:01 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a_head)
{
	int	prev_value;

	prev_value = INT_MIN;
	while (a_head)
	{
		if (prev_value > a_head->value)
			return (0);
		prev_value = a_head->value;
		a_head = a_head->next;
	}
	return (1);
}

int	find_min_pos(t_stack *a_head)
{
	int	pos;
	int	min_value;
	int	counter;

	pos = 0;
	counter = 0;
	min_value = INT_MAX;
	while (a_head)
	{
		if (a_head->value < min_value)
		{
			pos = counter;
			min_value = a_head->value;
		}
		a_head = a_head->next;
		counter++;
	}
	return (pos);
}

void	assign_rank(t_stack **stack_head)
{
	int		counter;
	t_stack	*node_to_rank;
	t_stack	*cpy;

	node_to_rank = *stack_head;
	while (node_to_rank)
	{
		counter = 0;
		cpy = *stack_head;
		while (cpy)
		{
			if (node_to_rank->value > cpy->value)
				counter++;
			cpy = cpy->next;
		}
		node_to_rank->rank = counter;
		node_to_rank = node_to_rank->next;
	}
}
