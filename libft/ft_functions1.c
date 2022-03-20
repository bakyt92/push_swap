#include "../push_swap.h"

int ft_atoi(char *str, s_allData *stacks)
{
	long number;
	int znak;

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
		return (1);
}