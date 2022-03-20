#include "../push_swap.h"

int	ft_hasvalue(s_list *l, int val)
{
	while (l)
	{
		if (l->value == val)
			return (1);
		l = l->next;
	}
	return (0);
}

void	push_stack(s_list **stack, int val, int tag, s_allData *stacks)
{
	s_list *elem;
	s_list *last_el;

	last_el = *stack;
	if (ft_hasvalue(*stack, val))
		ft_error("Error\n", stacks);
	elem = malloc(sizeof(s_list));
	if (!elem)
		ft_error("Error\n", stacks);
	elem->next = NULL;
	elem->next_sorted = NULL;
	elem->value = val;
	elem->index = tag;
	if (last_el == NULL)
	{
		*stack = elem;
		return ;
	}
	while (last_el->next)
		last_el = last_el->next;
	last_el->next = elem;
	last_el->next_sorted = elem;
}
