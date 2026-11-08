/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:08:04 by jlucotte          #+#    #+#             */
/*   Updated: 2026/11/06 17:01:02 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_stack *stack, int value)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->prev;
	}
	return (0);
}

int	check_if_nmb(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	if (*s == '\0')
		return (0);
	while (ft_isdigit(*s))
		s++;
	return (*s == '\0');
}

void	handle_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

int	is_valid(t_stack *last, char *s)
{
	int	value;

	if (!check_if_nmb(s) || !ft_atoi_safe(s, &value))
		return (0);
	return (!is_duplicate(last, value));
}

t_stack	*parser(int argc, char **argv)
{
	t_stack	*node;
	t_stack	*last;

	last = NULL;
	if (argc < 2)
		handle_error();
	while (*argv)
	{
		node = NULL;
		if (is_valid(last, *argv))
			node = create_node(ft_atoi(*argv), last);
		if (!node)
		{
			last = get_list_head_from_last(last);
			clean_stack(&last);
			handle_error();
		}
		last = node;
		argv++;
	}
	return (get_list_head_from_last(last));
}
