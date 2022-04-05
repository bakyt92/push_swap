/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:07:12 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/03/27 21:30:10 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_allData	*stacks;
	t_list		*start;

	if (argc < 2)
		return (0);
	if (!ft_init_struct(&stacks))
		return (0);
	stacks->print = 1;
	read_arguments(argc, argv, stacks);
	if (!ft_ordered(stacks))
	{
		start = stacks->stack_a;
		ft_indexing(start, stacks);
		if (stacks->max < 6)
			ft_sort_small(stacks);
		else
			ft_sort_big(stacks);
	}
	if (stacks->stack_a)
		ft_free_list(&(stacks->stack_a));
	if (stacks->stack_b)
		ft_free_list(&(stacks->stack_b));
	free(stacks);
	return (0);
}
