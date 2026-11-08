/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 23:11:22 by jlucotte          #+#    #+#             */
/*   Updated: 2026/11/02 13:15:19 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr_logic(t_stack **stack_head)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;

	if (count_node(*stack_head) <= 1)
		return (0);
	first = *stack_head;
	last = get_list_last_from_head(first);
	last->next = first;
	before_last = last->prev;
	before_last->next = NULL;
	last->prev = NULL;
	first->prev = last;
	*stack_head = last;
	return (1);
}

int	rra(t_stack **stack_head)
{
	if (rr_logic(stack_head))
		return (ft_printf("rra\n"), bench_count(OP_RRA), 1);
	return (0);
}

int	rrb(t_stack **stack_head)
{
	if (rr_logic(stack_head))
		return (ft_printf("rrb\n"), bench_count(OP_RRB), 1);
	return (0);
}

int	rrr(t_stack **a_head, t_stack **b_head)
{
	int	done_a;
	int	done_b;

	done_a = rr_logic(a_head);
	done_b = rr_logic(b_head);
	if (done_a || done_b)
		return (ft_printf("rrr\n"), bench_count(OP_RRR), 1);
	return (0);
}
