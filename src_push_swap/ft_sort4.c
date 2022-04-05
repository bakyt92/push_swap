/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:51:48 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/04/06 00:52:53 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_big(t_allData *stacks)
{
	size_t	size;
	size_t	counter;

	size = ft_lst_size(stacks->stack_a);
	if (size <= 15)
		counter = 3;
	else if (size <= 100)
		counter = size / 10;
	else if (size <= 300)
		counter = size / 15;
	else if (size <= 400)
		counter = size / 20;
	else if (size <= 500)
		counter = size / 23;
	else if (size <= 1000)
		counter = size / 30;
	else
		counter = (size % 1000 * 2 + 30);
	while (stacks->stack_a)
		ft_butterfly(stacks, counter);
	while (stacks->stack_b)
		ft_sort_after_butterfly(stacks);
}

void	ft_butterfly(t_allData *stacks, int counter)
{
	int	i;

	i = 1;
	while (stacks->stack_a)
	{
		if (stacks->stack_a->index <= i)
		{
			ft_push_b(stacks);
			ft_rotate_b(stacks);
			i++;
		}
		else if (stacks->stack_a->index <= i + counter)
		{
			ft_push_b(stacks);
			i++;
		}
		else
			ft_rotate_a(stacks);
	}
}

void	ft_sort_after_butterfly(t_allData *stacks)
{
	t_list	*max;
	int		destination;

	max = ft_indicate_max(stacks);
	destination = ft_find_destination(stacks, max);
	if (stacks->stack_b == max)
		ft_push_a(stacks);
	else if (destination > ft_lst_size(stacks->stack_b) / 2)
		ft_reverse_rotate_b(stacks);
	else
		ft_rotate_b(stacks);
}

t_list	*ft_indicate_max(t_allData *stacks)
{
	int		i;
	t_list	*max;
	t_list	*current;

	i = 0;
	max = stacks->stack_b;
	current = stacks->stack_b;
	if (!max)
		return (NULL);
	while (i < ft_lst_size(stacks->stack_b))
	{
		if (current->index > max->index)
			max = current;
		current = current->next;
		i++;
	}
	return (max);
}

int	ft_find_destination(t_allData *stacks, t_list *max)
{
	t_list	*start;
	int		i;

	i = 0;
	start = stacks->stack_b;
	while (start != max)
	{
		i++;
		start = start->next;
	}
	return (i);
}
