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

/* reads the leading --strategy / --bench flags, in any order */
static int	parse_flags(char ***argv, char **strategy, int *bench)
{
	char	*found;

	*strategy = NULL;
	*bench = 0;
	while (**argv)
	{
		found = get_strategy(**argv);
		if (found && *strategy)
			return (0);
		if (found)
			*strategy = found;
		else if (is_strategy(**argv, FLAG_BENCH) && !*bench)
			*bench = 1;
		else if (is_strategy(**argv, FLAG_BENCH))
			return (0);
		else
			break ;
		(*argv)++;
	}
	if (!*strategy)
		*strategy = STRATEGY_ADAPTIVE;
	return (1);
}

int	push_swap(int argc, char **argv)
{
	t_stack	*stack_a_head;
	char	*strategy;
	int		bench;
	double	disorder;

	if (argc < 2)
		return (0);
	argv++;
	if (!parse_flags(&argv, &strategy, &bench))
		handle_error();
	if (!*argv)
		return (0);
	stack_a_head = parser(2, argv);
	disorder = compute_disorder(stack_a_head);
	strat_picker(strategy, &stack_a_head);
	if (bench)
		print_bench(disorder);
	clean_stack(&stack_a_head);
	return (0);
}
