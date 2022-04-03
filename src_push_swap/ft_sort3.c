#include "../push_swap.h"

void	ft_sort_small(t_allData *stacks)
{
	t_list	*t;

	t = stacks->stack_a;
	while (ft_lst_size(stacks->stack_a) > 3)
	{
		if (ft_lst_size(stacks->stack_a) == 4)
		{
			ft_has_index(t, 4);
			ft_3args(stacks);
		}
		if (ft_lst_size(stacks->stack_a) == 5)
			ft_5args(stacks);
	}
	if (ft_lst_size(stacks->stack_a) == 3)
		ft_3args(stacks);
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

void	ft_5args(t_allData *stacks)
{
	t_list	*t;
	int		min;
	int		cur;

	while (ft_has_index(stacks->stack_a, 0) || ft_has_index(stacks->stack_a,
															stacks->max - 1))
	{
		t = stacks->stack_a;
		min = stacks->max;
		while (t)
		{
			if (t->index == 0 || t->index == stacks->max - 1)
			{
				cur = ft_count_to_top(stacks->stack_a, t->index);
				if (ft_positive(cur) < ft_positive(min))
					min = cur;
			}
			t = t->next;
		}
		if (min == 0)
			ft_push_b(stacks);
		if (min < 0)
			ft_reverse_rotate_a(stacks);
		if (min > 0)
			ft_rotate_a(stacks);
	}
}
