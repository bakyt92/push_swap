#include "../push_swap.h"

void	ft_rotate_b_a(s_allData *stacks)
{
	ft_push_bottom(stacks->stack_a);
	ft_push_bottom(stacks->stack_b);
	if (stacks->print)
		ft_putstr("rr");
}

void	ft_swap_lst(s_list *stacks)
{
	s_list	*tmp;
	s_list	*add_element;

	if (!stacks || !stacks->next)
		return ;
	add_element = stacks->next->next;
	tmp = stacks;
	stacks = stacks->next;
	stacks->next = tmp;
	tmp->next = add_element;
}

void	ft_push_top12(s_list *place1, s_list *place2)
{
	s_list	*top;
	if (!place1)
		return ;
	top = place1;
	place1 = top->next;
	if (place2)
		top->next = place2;
	else
		top->next = NULL;
	place2 = top;
}

void	ft_push_bottom(s_list *t)
{
	s_list *top;
	s_list *tmp;

	if(!t || !t->next)
		return ;
	top = t;
	t = t->next;
	tmp = t;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = top;
	top->next = NULL;
}

void	ft_push_top(s_list *t)
{
	s_list	*tmp;
	s_list	*last;

	if(!t || !t->next)
		return ;
	last = t;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = t;
	t = last;
	tmp->next = NULL;
}