/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:05:48 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/04/06 01:44:15 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lst_size(t_list *t)
{
	int		i;
	t_list	*begin;

	i = 0;
	begin = t;
	while (t)
	{
		i++;
		t = t->next;
		if (begin == t)
			break ;
	}
	return (i);
}
