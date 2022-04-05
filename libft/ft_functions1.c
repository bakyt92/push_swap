/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:05:39 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/03/20 21:05:44 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_atoi(char *str, t_allData *stacks)
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

int	ft_ordered(t_allData *stacks)
{
	int		pred;
	t_list	*t;
	t_list	*begin;

	if (stacks->stack_b)
		return (0);
	if (!stacks->stack_a)
		return (1);
	t = stacks->stack_a;
	begin = t;
	pred = t->value;
	while (t)
	{
		if (pred > t->value)
			return (0);
		pred = t->value;
		t = t->next;
		if (begin == t)
			break ;
	}
	return (1);
}
