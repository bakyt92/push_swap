
#include "../push_swap.h"

void ft_swap_a(s_allData *stacks)
{
	ft_swap_lst(stacks->stack_a);
	if (stacks->print)
		ft_putstr("sa");
}

void ft_swap_b(s_allData *stacks)
{
	ft_swap_lst(stacks->stack_b);
	if (stacks->print)
		ft_putstr("sb");
}

void ft_swap_b_a(s_allData *stacks)
{
	ft_swap_lst(stacks->stack_a);
	ft_swap_lst(stacks->stack_b);
	if (stacks->print)
		ft_putstr("ss");
}
