/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:10:33 by jlucotte          #+#    #+#             */
/*   Updated: 2026/11/05 17:58:36 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_bit_size(int stack_size)
{
	int	bits;

	bits = 0;
	while (((stack_size - 1) >> bits) != 0)
		bits++;
	return (bits);
}

void	complex_sort(t_stack **a_head, t_stack **b_head)
{
	int	stack_size;
	int	max_bits;
	int	i;
	int	y;

	i = 0;
	assign_rank(a_head);
	stack_size = count_node(*a_head);
	max_bits = get_bit_size(stack_size);
	while (i < max_bits)
	{
		y = 0;
		while (y < stack_size)
		{
			if ((((*a_head)->rank >> i) & 1) == 0)
				pb(a_head, b_head);
			else
				ra(a_head);
			y++;
		}
		while (*b_head)
			pa(a_head, b_head);
		i++;
	}
}
