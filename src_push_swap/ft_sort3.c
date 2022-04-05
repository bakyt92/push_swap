#include "../push_swap.h"

void	ft_sort_small(t_allData *stacks)
{
	if (ft_lst_size(stacks->stack_a) == 5)
		ft_5args(stacks);
	else if (ft_lst_size(stacks->stack_a) == 4)
		ft_4args(stacks);
	else if (ft_lst_size(stacks->stack_a) == 3)
		ft_3args(stacks);
	else if (ft_lst_size(stacks->stack_a) == 2)
	{
		if (stacks->stack_a->index > stacks->stack_a->next->index)
			ft_swap_a(stacks);
	}
}
void	ft_3args(t_allData *stacks)
{
	int	a;
	int	b;
	int	c;

	a = stacks->stack_a->index;
	b = stacks->stack_a->next->index;
	c = stacks->stack_a->previous->index;

	if (a > b && a > c)
		ft_rotate_a(stacks);
	else if (b > a && b > c)
		ft_reverse_rotate_a(stacks);
	a = stacks->stack_a->index;
	b = stacks->stack_a->next->index;
	if (a > b)
		ft_swap_a(stacks);
}

void	ft_4args(t_allData *stacks)
{
	while (ft_lst_size(stacks->stack_a) > 3)
	{
		if (stacks->stack_a->index == 1)
			ft_push_b(stacks);
		ft_rotate_a(stacks);
	}
	ft_3args(stacks);
	ft_push_a(stacks);
}

void	ft_5args(t_allData *stacks)
{
	while (ft_lst_size(stacks->stack_a) > 3)
	{
		if (stacks->stack_a->index == 1 || stacks->stack_a->index == 2)
			ft_push_b(stacks);
		else
			ft_rotate_a(stacks);
	}
	ft_3args(stacks);
	ft_push_a(stacks);
	ft_push_a(stacks);
	if (stacks->stack_a->index > stacks->stack_a->next->index)
		ft_swap_a(stacks);
}
