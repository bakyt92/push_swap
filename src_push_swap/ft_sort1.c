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

int	ft_has_index(s_list *t, int index)
{
	while (t)
	{
		if (t->index == index)
			return (1);
		t = t->next;
	}
	return (0);
}

int	ft_count_to_top(s_list *t, int index)
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
}

void	ft_indexing(s_list *start, s_allData *stacks)
{
	int	i;

	i = 0;
	while (start)
	{
		start->index = i++;
		start = start->next_sorted;
	}
	stacks->max = i;
}

void	ft_5args(s_allData *stacks)
{
	s_list	*t;
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
