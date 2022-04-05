/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:06:51 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/04/06 01:00:48 by ufitzhug         ###   ########.fr       */
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
