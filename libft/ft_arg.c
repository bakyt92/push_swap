/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:05:13 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/03/20 21:05:22 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, '\n', 1);
}

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_arg(char *str)
{
	int i;

	i = 0;
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
