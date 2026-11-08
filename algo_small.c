/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerman <tgerman@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-06 10:13:28 by tgerman           #+#    #+#             */
/*   Updated: 2026-11-06 10:13:28 by tgerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **a_head)
{
	int	first;
	int	second;
	int	third;

	first = (*a_head)->value;
	second = (*a_head)->next->value;
	third = (*a_head)->next->next->value;
	if (first > second && first > third)
		ra(a_head);
	else if (second > first && second > third)
		rra(a_head);
	if ((*a_head)->value > (*a_head)->next->value)
		sa(a_head);
}

void	small_sort(t_stack **a_head, t_stack **b_head)
{
	if (is_sorted(*a_head))
		return ;
	if (count_node(*a_head) == 2)
	{
		sa(a_head);
		return ;
	}
	while (count_node(*a_head) > 3)
	{
		bring_to_top(a_head, find_min_pos(*a_head));
		pb(a_head, b_head);
	}
	sort_three(a_head);
	while (*b_head)
		pa(a_head, b_head);
}
