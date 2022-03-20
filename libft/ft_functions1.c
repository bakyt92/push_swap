#include "../push_swap.h"

void	ft_sw_list(s_list **pred, s_list *last)
{
	s_list	*swap;

	swap = *pred;
	*pred = last->next_sorted;
	swap->next_sorted = last->next_sorted->next_sorted;
	(*pred)->next_sorted = swap;
}

int ft_atoi(char *str, s_allData *stacks)
{
	long	number;
	int		znak;

	znak = 1;
	number = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
	|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			znak = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		number = number * 10 + (*str - '0');
		if ((znak == 1 && number > 0x7FFFFFFF) || (znak == -1 && number >
		0x80000000))
			ft_error("Error\n", stacks);
		str++;
	}
	return ((int)number * znak);
}

int	ft_ordered(s_allData *stacks)
{
	int	pred;
	s_list *t;

	if (stacks->stack_b)
		return (0);
	if (!stacks->stack_a)
		return (1);
	t = stacks->stack_a;
	pred = t->value;
	while (t)
	{
		if (pred > t->value)
			return (0);
		pred = t->value;
		t = t->next;
	}
	return (1);
}