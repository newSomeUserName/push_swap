/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:08:04 by jlucotte          #+#    #+#             */
/*   Updated: 2026/11/06 17:34:36 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_strategy(char *s, char *strategy)
{
	return (ft_strncmp(s, strategy, ft_strlen(strategy) + 1) == 0);
}

static char	*get_strategy(char *strategy_s)
{
	if (is_strategy(strategy_s, STRATEGY_COMPLEX))
		return (STRATEGY_COMPLEX);
	if (is_strategy(strategy_s, STRATEGY_MEDIUM))
		return (STRATEGY_MEDIUM);
	if (is_strategy(strategy_s, STRATEGY_SIMPLE))
		return (STRATEGY_SIMPLE);
	if (is_strategy(strategy_s, STRATEGY_ADAPTIVE))
		return (STRATEGY_ADAPTIVE);
	return (NULL);
}

int	push_swap(int argc, char **argv)
{
	t_stack	*stack_a_head;
	char	*strategy;

	if (argc < 2)
		return (0);
	strategy = get_strategy(*(argv + 1));
	if (strategy)
	{
		argv++;
		argc--;
	}
	else
		strategy = STRATEGY_ADAPTIVE;
	if (argc < 2)
		return (0);
	stack_a_head = parser(argc, argv + 1);
	strat_picker(strategy, &stack_a_head);
	clean_stack(&stack_a_head);
	return (0);
}
