/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rr_np.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:24:07 by jlucotte          #+#    #+#             */
/*   Updated: 2026/11/02 13:15:36 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_no_print(t_stack **stack_head)
{
	rr_logic(stack_head);
}

void	rrb_no_print(t_stack **stack_head)
{
	rr_logic(stack_head);
}

void	rrr_no_print(t_stack **a_head, t_stack **b_head)
{
	rr_logic(a_head);
	rr_logic(b_head);
}
