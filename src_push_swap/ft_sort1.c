/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:06:37 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/04/06 01:04:07 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
}
