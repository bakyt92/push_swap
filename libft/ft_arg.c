#include "../push_swap.h"

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

void ft_error (char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, str[i], 1);
		i++;
	}
	// ОЧИСТКА ПАМЯТИ
	return ;
}