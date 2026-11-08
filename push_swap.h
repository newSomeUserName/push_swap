/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:04:50 by jlucotte          #+#    #+#             */
/*   Updated: 2026/11/06 18:16:29 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

# define DISORDER_LOW 0.2
# define DISORDER_HIGH 0.5

# define STRATEGY_SIMPLE "--simple"
# define STRATEGY_MEDIUM "--medium"
# define STRATEGY_COMPLEX "--complex"
# define STRATEGY_ADAPTIVE "--adaptive"
# define FLAG_BENCH "--bench"

# define NAME_SIMPLE "Simple / O(n^2)"
# define NAME_MEDIUM "Medium / O(n√n)"
# define NAME_COMPLEX "Complex / O(n log n)"
# define NAME_ADAPT_LOW "Adaptive / O(n^2)"
# define NAME_ADAPT_MID "Adaptive / O(n√n)"
# define NAME_ADAPT_HIGH "Adaptive / O(n log n)"

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_op;

typedef struct s_bench
{
	int		counts[OP_COUNT];
	int		total;
	char	*strategy;
}	t_bench;

typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// list fn
t_stack	*create_node(int value, t_stack *prev);
int		count_node(t_stack *stack_head);
t_stack	*get_list_head_from_last(t_stack *stack);
t_stack	*get_list_last_from_head(t_stack *stack);
void	*clean_stack(t_stack **head);

void	handle_error(void);
t_stack	*parser(int argc, char **argv);
int		push_swap(int argc, char **argv);
int		is_strategy(char *s, char *strategy);

// operation fn
int		swap_logic(t_stack **list_head);
int		r_logic(t_stack **stack_head);
int		rr_logic(t_stack **stack_head);
int		sa(t_stack **stack_head);
int		sb(t_stack **stack_head);
int		ss(t_stack **a_head, t_stack **b_head);
int		pa(t_stack **a_head, t_stack **b_head);
int		pb(t_stack **a_head, t_stack **b_head);
int		ra(t_stack **stack_head);
int		rb(t_stack **stack_head);
int		rr(t_stack **a_head, t_stack **b_head);
int		rra(t_stack **stack_head);
int		rrb(t_stack **stack_head);
int		rrr(t_stack **a_head, t_stack **b_head);

// operation bonus
void	pa_no_print(t_stack **a_head, t_stack **b_head);
void	pb_no_print(t_stack **a_head, t_stack **b_head);
void	sa_no_print(t_stack **stack_head);
void	sb_no_print(t_stack **stack_head);
void	ss_no_print(t_stack **a_head, t_stack **b_head);
void	ra_no_print(t_stack **stack_head);
void	rb_no_print(t_stack **stack_head);
void	rr_no_print(t_stack **a_head, t_stack **b_head);
void	rra_no_print(t_stack **stack_head);
void	rrb_no_print(t_stack **stack_head);
void	rrr_no_print(t_stack **a_head, t_stack **b_head);

// algo utils
int		is_sorted(t_stack *a_head);
int		find_min_pos(t_stack *a_head);
void	assign_rank(t_stack **stack_head);
void	strat_picker(char *strat, t_stack **a_head);

// simple algo
void	bring_to_top(t_stack **a_head, int pos);
void	simple_sort(t_stack **a_head, t_stack **b_head);

// small algo (5 numbers or fewer)
void	small_sort(t_stack **a_head, t_stack **b_head);

// medium algo
void	medium_sort(t_stack **stack_a, t_stack **stack_b);

// complex algo
void	complex_sort(t_stack **a_head, t_stack **b_head);

// adaptive algo
double	compute_disorder(t_stack *a_head);
void	adaptive_sort(t_stack **a_head, t_stack **b_head);

// bench
t_bench	*get_bench(void);
void	bench_count(int op);
void	bench_set_strategy(char *name);
void	print_bench(double disorder);
#endif
