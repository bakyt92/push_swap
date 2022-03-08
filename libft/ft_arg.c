#include "../push_swap.h"

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	check_arg(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' &&  str[i] <= '9')
			i++;
		else
			return(1);
	}
	return (0);
}

void ft_error (char *str, s_allData *stacks)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(2, str[i], 1);
		i++;
	}
	ft_free_list(&(stacks->stack_a));
	ft_free_list(&(stacks->stack_b));
	exit(EXIT_FAILURE);
}