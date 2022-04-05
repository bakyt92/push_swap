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

void	ft_sorting(t_list **stacks)
{
	t_list	*last;
	t_list	*pred;

	pred = NULL;
	last = *stacks;
	while (last && last->next_sorted)
	{
		if (last->value - last->next_sorted->value > 0)
		{
			if (pred == NULL)
				ft_sw_list(stacks, last);
			else
				ft_sw_list(&(pred->next_sorted), last);
			last = *stacks;
			pred = NULL;
		}
		else
		{
			pred = last;
			last = last->next_sorted;
		}
	}
}



int	main(int argc, char **argv)
{
	t_allData	*stacks;
	t_list		*start;

	if (argc < 2)
		return (0);
	if (!ft_init_struct(&stacks))
		return (0);
	read_arguments(argc, argv, stacks);
	if (!ft_ordered(stacks))
	{
		start = stacks->stack_a;
		ft_sorting(&start);
		ft_indexing(start, stacks);
		if (stacks->max < 6)
		{
			ft_sort_small(stacks);
//			return (0);
		}
		else
			ft_sort_big(stacks);
//		if (stacks->max == 5)
//			ft_5args(stacks);
//		ft_reshenie(stacks, 1);
	}
	if (stacks->stack_a)
		ft_free_list(&(stacks->stack_a));
	free(stacks);
//	free(start);
//	if (stacks->stack_b)
//		ft_free_list(&(stacks->stack_b));
//	start = NULL;
//	stacks = NULL;
	return (0);
}
