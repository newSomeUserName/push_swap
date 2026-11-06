/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:36:41 by jlucotte          #+#    #+#             */
/*   Updated: 2026/11/06 18:15:57 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack **dst, t_stack **src)
{
	t_stack	*node;

	if (*src == NULL || *dst == *src)
		return (0);
	node = *src;
	*src = node->next;
	if (*src)
		(*src)->prev = NULL;
	node->next = *dst;
	if (*dst)
		(*dst)->prev = node;
	*dst = node;
	return (1);
}

int	pa(t_stack **a_head, t_stack **b_head)
{
	if (push(a_head, b_head))
		return (ft_printf("pa\n"), 1);
	return (0);
}

int	pb(t_stack **a_head, t_stack **b_head)
{
	if (push(b_head, a_head))
		return (ft_printf("pb\n"), 1);
	return (0);
}

void	pa_no_print(t_stack **a_head, t_stack **b_head)
{
	push(a_head, b_head);
}

void	pb_no_print(t_stack **a_head, t_stack **b_head)
{
	push(b_head, a_head);
}
