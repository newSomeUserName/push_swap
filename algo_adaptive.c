/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 18:00:00 by jlucotte          #+#    #+#             */
/*   Updated: 2026/11/05 18:00:00 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Follows the subject pseudo-code: mistakes / total_pairs, from 0.0 to 1.0 */
double	compute_disorder(t_stack *a_head)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*i;
	t_stack	*j;

	mistakes = 0;
	total_pairs = 0;
	i = a_head;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}

void	adaptive_sort(t_stack **a_head, t_stack **b_head)
{
	double	disorder;

	disorder = compute_disorder(*a_head);
	if (disorder == 0.0)
		return ;
	if (count_node(*a_head) <= 5)
		small_sort(a_head, b_head);
	else if (disorder < DISORDER_LOW)
		simple_sort(a_head, b_head);
	else if (disorder < DISORDER_HIGH)
		medium_sort(a_head, b_head);
	else
		complex_sort(a_head, b_head);
}
