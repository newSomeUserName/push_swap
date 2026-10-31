

#include "push_swap.h"

static void swap_top(t_stack **head)
{
    t_stack *prev;
    prev = (*head)->prev;
    if (!prev)
        return;
    prev->next = NULL;
    (*head)->next = prev;
    (*head)->prev = prev->prev;
    if (prev->prev)
        prev->prev->next = *head;
    prev->prev = *head;
    *head = prev;
}
void sa(t_stack **stack)
{
    if (*stack)
        swap_top(stack);
}
void sb(t_stack **stack)
{
    if (*stack)
        swap_top(stack);
}
void ss(t_stack **stack_a, t_stack **stack_b)
{
    sa(stack_a);
    sb(stack_b);
}