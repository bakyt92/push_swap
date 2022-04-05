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
