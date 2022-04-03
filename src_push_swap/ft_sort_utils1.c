/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:06:28 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/03/23 02:14:59 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_init_reshenie(t_allData *stacks)
{
	stacks->big = ft_find_biggest_loop(stacks->stack_a, 1);
	stacks->size = ft_lst_size(stacks->stack_a);
	stacks->generation = ft_maximum(1, (int)(stacks->max / 150.0));
	stacks->gen_size = stacks->max / stacks->generation;
}

int	ft_make_loop(t_list *tmp, t_list *begin, int number)
{
	t_list	*loop;
	int		max_index;
	int		count;

	max_index = -1;
	count = 0;
	loop = begin;
	while (loop)
	{
		if (number)
			loop->flag = 0;
		if (loop->index > max_index)
		{
			max_index = loop->index;
			count++;
			if (number)
				loop->flag = 1;
		}
		loop = loop->next;
		if (loop == NULL)
			loop = tmp;
		if (loop == begin)
			break ;
	}
	return (count);
}

int	ft_find_biggest_loop(t_list *begin, int number)
{
	t_list	*t;
	int		maximum;
	int		count;
	t_list	*max_flag;
	t_list	*mark_start;

	maximum = 0;
	t = begin;
	mark_start = t;
	while (t)
	{
		count = ft_make_loop(begin, t, 0);
		if (count > maximum)
		{
			maximum = count;
			max_flag = t;
		}
		t = t->next;
		if (t == mark_start)
			break ;
	}
	if (number)
		ft_make_loop(begin, max_flag, 1);
	return (maximum);
}

int	ft_isswapable(t_list *tmp)
{
	t_list	example;
	t_list	example2;
	int		counter1;
	int		counter2;

	example.next = &example2;
	example.index = tmp->next->index;
	example2.next = tmp->next->next;
	example2.index = tmp->index;
	counter1 = ft_find_biggest_loop(tmp, 0);
	counter2 = ft_find_biggest_loop(&example2, 0);
	if (counter2 > counter1)
		return (1);
	return (0);
}

t_list	*ft_blizko_ingroup(t_list *tmp, int gen, int generation_size)
{
	t_list	*blizko;
	t_list	*current;
	int		distance;
	int		current_distance;

	distance = gen * generation_size;
	blizko = NULL;
	current = tmp;
	while (current && current->next != tmp)
	{
		if (current->index <= generation_size * gen && !current->flag)
		{
			current_distance = ft_count_to_top(tmp, current->index);
			if (ft_positive(current_distance) < ft_positive(distance))
			{
				distance = current_distance;
				blizko = current;
				if (distance == 0)
					break ;
			}
		}
		current = current->next;
	}
	return (blizko);
}
