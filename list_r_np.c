/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_r_np.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:24:07 by jlucotte          #+#    #+#             */
/*   Updated: 2026/11/02 13:15:36 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_no_print(t_stack **stack_head)
{
	r_logic(stack_head);
}

void	rb_no_print(t_stack **stack_head)
{
	r_logic(stack_head);
}

void	rr_no_print(t_stack **a_head, t_stack **b_head)
{
	r_logic(a_head);
	r_logic(b_head);
}
