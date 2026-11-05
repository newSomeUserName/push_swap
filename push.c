

#include "push_swap.h"

static void push_from_to_stack(t_stack **from_stack, t_stack **to_stack)
{
    if (!(*to_stack))
        *to_stack = (*from_stack);
    else
        (*to_stack)->next = *from_stack;
    if ((*from_stack)->prev)
    {
        (*from_stack)->prev->next = NULL;
        *from_stack = (*from_stack)->prev;
        (*from_stack)->prev = NULL;
    }
    else
        *from_stack = NULL;
}
void pa(t_stack **stack_a, t_stack **stack_b)
{
    if (*stack_b)
        push_from_to_stack(stack_b, stack_a);
}
void pb(t_stack **stack_a, t_stack **stack_b)
{
    if (*stack_a)
        push_from_to_stack(stack_a, stack_b);
}