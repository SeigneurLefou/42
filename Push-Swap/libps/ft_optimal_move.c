#include "push_swap.h"

void    ft_optimal_move(t_list **stack, int min_index, int max_index)
{
    int     first_el;
    int     last_el;
    t_list  *tmp;

    i = 0;
    tmp = *stack;
    while (tmp)
    {
        if (min_index <= tmp->index && tmp->index <= max_index)
            if (!first_el)
                first_el = ft_lstsize(stack) - ft_lstsize(tmp);
            last_el = ft_lstsize(tmp);
        tmp = tmp->next;
    }
    if (first_el < last_el)
        rra(stack);
    else
        ra(stack);
}