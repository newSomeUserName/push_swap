/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 14:26:34 by jlucotte          #+#    #+#             */
/*   Updated: 2026/11/04 15:35:36 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_logic(t_stack **list_head)
{
	t_stack	*first;
	t_stack	*second;

	if (!list_head || !*list_head || count_node(*list_head) <= 1)
		return (0);
	first = *list_head;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	second->next = first;
	second->prev = NULL;
	*list_head = second;
	return (1);
}

int	sa(t_stack **list_head)
{
	if (swap_logic(list_head))
		return (ft_printf("sa\n"), 1);
	return (0);
}

int	sb(t_stack **list_head)
{
	if (swap_logic(list_head))
		return (ft_printf("sb\n"), 1);
	return (0);
}

int	ss(t_stack **a_head, t_stack **b_head)
{
	int	done_a;
	int	done_b;

	done_a = swap_logic(a_head);
	done_b = swap_logic(b_head);
	if (done_a || done_b)
		return (ft_printf("ss\n"), 1);
	return (0);
}
