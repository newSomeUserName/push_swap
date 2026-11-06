/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:42:19 by jlucotte          #+#    #+#             */
/*   Updated: 2026/11/06 18:51:07 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exec_swap_push(char *gnl, t_stack **a, t_stack **b)
{
	if (ft_strnstr(gnl, "pa\n", 3))
		pa_no_print(a, b);
	else if (ft_strnstr(gnl, "pb\n", 3))
		pb_no_print(a, b);
	else if (ft_strnstr(gnl, "sa\n", 3))
		sa_no_print(a);
	else if (ft_strnstr(gnl, "sb\n", 3))
		sb_no_print(a);
	else if (ft_strnstr(gnl, "ss\n", 3))
		ss_no_print(a, b);
	else
		return (0);
	return (1);
}

static int	exec_rotate(char *gnl, t_stack **a, t_stack **b)
{
	if (ft_strnstr(gnl, "ra\n", 3))
		ra_no_print(a);
	else if (ft_strnstr(gnl, "rb\n", 3))
		rb_no_print(b);
	else if (ft_strnstr(gnl, "rr\n", 3))
		rr_no_print(a, b);
	else if (ft_strnstr(gnl, "rra\n", 4))
		rra_no_print(a);
	else if (ft_strnstr(gnl, "rrb\n", 4))
		rrb_no_print(b);
	else if (ft_strnstr(gnl, "rrr\n", 4))
		rrr_no_print(a, b);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*gnl;
	t_stack	*a;
	t_stack	*b;

	a = parser(argc, argv + 1);
	b = NULL;
	while (!is_sorted(a))
	{
		gnl = get_next_line(0);
		if (!exec_swap_push(gnl, &a, &b) && !exec_rotate(gnl, &a, &b))
		{
			if (ft_strnstr(gnl, "\n", 1))
			{
				ft_printf("KO\n");
				return (0);
			}
			handle_error();
		}
	}
	ft_printf("OK\n");
	return (0);
}
