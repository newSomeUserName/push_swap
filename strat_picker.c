/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_picker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 16:52:34 by jlucotte          #+#    #+#             */
/*   Updated: 2026/11/06 17:09:07 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	strat_picker(char *strat, t_stack **a_head)
{
	t_stack	*b_stack;

	b_stack = NULL;
	if (is_strategy(strat, STRATEGY_SIMPLE))
		bench_set_strategy(NAME_SIMPLE);
	else if (is_strategy(strat, STRATEGY_MEDIUM))
		bench_set_strategy(NAME_MEDIUM);
	else if (is_strategy(strat, STRATEGY_COMPLEX))
		bench_set_strategy(NAME_COMPLEX);
	else
		bench_set_strategy(NAME_ADAPT_LOW);
	if (is_sorted(*a_head))
		return ;
	if (is_strategy(strat, STRATEGY_SIMPLE))
		simple_sort(a_head, &b_stack);
	else if (is_strategy(strat, STRATEGY_MEDIUM))
		medium_sort(a_head, &b_stack);
	else if (is_strategy(strat, STRATEGY_COMPLEX))
		complex_sort(a_head, &b_stack);
	else
		adaptive_sort(a_head, &b_stack);
}
