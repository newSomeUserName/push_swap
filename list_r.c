/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:24:07 by jlucotte          #+#    #+#             */
/*   Updated: 2026/11/02 13:15:36 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_logic(t_stack **stack_head)
{
	t_stack	*first;
	t_stack	*last;

	if (count_node(*stack_head) <= 1)
		return (0);
	first = *stack_head;
	last = get_list_last_from_head(first);
	*stack_head = first->next;
	(*stack_head)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	return (1);
}

int	ra(t_stack **stack_head)
{
	if (r_logic(stack_head))
		return (ft_printf("ra\n"), 1);
	return (0);
}

int	rb(t_stack **stack_head)
{
	if (r_logic(stack_head))
		return (ft_printf("rb\n"), 1);
	return (0);
}

int	rr(t_stack **a_head, t_stack **b_head)
{
	int	done_a;
	int	done_b;

	done_a = r_logic(a_head);
	done_b = r_logic(b_head);
	if (done_a || done_b)
		return (ft_printf("rr\n"), 1);
	return (0);
}
