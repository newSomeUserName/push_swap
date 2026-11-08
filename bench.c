/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerman <tgerman@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 21:30:00 by tgerman           #+#    #+#             */
/*   Updated: 2026/11/06 21:30:00 by tgerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* one shared instance, kept as a static local (no global variable) */
t_bench	*get_bench(void)
{
	static t_bench	bench;

	return (&bench);
}

void	bench_count(int op)
{
	t_bench	*bench;

	bench = get_bench();
	bench->counts[op]++;
	bench->total++;
}

void	bench_set_strategy(char *name)
{
	get_bench()->strategy = name;
}

static void	put_counts(t_bench *bench, int from, int to)
{
	static char	*names[OP_COUNT] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};

	ft_putstr_fd("[bench]", STDERR_FILENO);
	while (from <= to)
	{
		ft_putstr_fd(" ", STDERR_FILENO);
		ft_putstr_fd(names[from], STDERR_FILENO);
		ft_putstr_fd(":  ", STDERR_FILENO);
		ft_putnbr_fd(bench->counts[from], STDERR_FILENO);
		from++;
	}
	ft_putstr_fd("\n", STDERR_FILENO);
}

/* disorder is 0.0 .. 1.0, printed as a percentage with two decimals */
void	print_bench(double disorder)
{
	t_bench	*bench;
	long	pct;

	bench = get_bench();
	pct = (long)(disorder * 10000.0 + 0.5);
	ft_putstr_fd("[bench] disorder:  ", STDERR_FILENO);
	ft_putnbr_fd(pct / 100, STDERR_FILENO);
	ft_putchar_fd('.', STDERR_FILENO);
	ft_putchar_fd('0' + (pct / 10) % 10, STDERR_FILENO);
	ft_putchar_fd('0' + pct % 10, STDERR_FILENO);
	ft_putstr_fd("%\n[bench] strategy:  ", STDERR_FILENO);
	ft_putstr_fd(bench->strategy, STDERR_FILENO);
	ft_putstr_fd("\n[bench] total_ops:  ", STDERR_FILENO);
	ft_putnbr_fd(bench->total, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	put_counts(bench, OP_SA, OP_PB);
	put_counts(bench, OP_RA, OP_RRR);
}
