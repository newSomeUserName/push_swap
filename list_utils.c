/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 14:04:52 by jlucotte          #+#    #+#             */
/*   Updated: 2026/11/06 17:28:53 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int value, t_stack *prev)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->rank = 0;
	new_node->next = NULL;
	new_node->prev = prev;
	if (prev)
		prev->next = new_node;
	return (new_node);
}

int	count_node(t_stack *stack_head)
{
	int	counter;

	counter = 0;
	while (stack_head)
	{
		counter++;
		stack_head = stack_head->next;
	}
	return (counter);
}

t_stack	*get_list_head_from_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}

t_stack	*get_list_last_from_head(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	*clean_stack(t_stack **head)
{
	t_stack	*next;

	while (*head)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
	}
	return (NULL);
}
