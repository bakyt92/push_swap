/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:06:37 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/03/20 21:17:05 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_has_index(t_list *t, int index)
{
	t_list	*begin;

	begin = t;
	while (t)
	{
		if (t->index == index)
			return (1);
		t = t->next;
		if (t == begin)
			break ;
	}
	return (0);
}

int	ft_count_to_top(t_list *t, int index)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lst_size(t);
	while (t)
	{
		if (t->index == index)
			break ;
		t = t->next;
		i++;
	}
	if (i > size / 2)
		i = i - size;
	return (i);
}

void	ft_indexing(t_list *start, t_allData *stacks)
{
	int		index;
	t_list	*temp;
	t_list	*current;

	current = start;

	while (current)
	{
		temp = current;
		index = 1;
		while (temp)
		{
			current->index = index;
			temp = temp->next;
			if (current->value > temp->value)
				current->index = index++;
			if (current == temp)
				break ;
		}
		current = current->next;
		if (current == start)
			break ;
	}
	stacks->max = ft_lst_size(start);
/*
	i = 0;
	while (start)
	{
		start->index = i++;
		start = start->next_sorted;
	}
	stacks->max = i;
*/
}

