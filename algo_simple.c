/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 14:25:55 by jlucotte          #+#    #+#             */
/*   Updated: 2026/11/04 16:34:28 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_to_top(t_stack **a_head, int pos)
{
	int	size_list;
	int	counter;
	int	amount_op;

	counter = 0;
	size_list = count_node(*a_head);
	if (pos <= size_list / 2)
	{
		while (counter < pos)
		{
			ra(a_head);
			counter++;
		}
	}
	else
	{
		amount_op = size_list - pos;
		while (counter < amount_op)
		{
			rra(a_head);
			counter++;
		}
	}
}

void	simple_sort(t_stack **a_head, t_stack **b_head)
{
	int	min_pos;

	if (is_sorted(*a_head))
		return ;
	while (count_node(*a_head) != 0)
	{
		min_pos = find_min_pos(*a_head);
		bring_to_top(a_head, min_pos);
		pb(a_head, b_head);
	}
	while (count_node(*b_head) != 0)
		pa(a_head, b_head);
}
