/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:05:48 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/03/20 21:05:52 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lst_size(s_list *t)
{
	int i;

	i = 0;
	while (t)
	{
		i++;
		t = t->next;
	}
	return (i);
}

int	ft_positive(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}
