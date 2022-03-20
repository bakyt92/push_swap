/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:06:51 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/03/20 21:19:32 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reshenie(s_allData *stacks, int gen)
{
	int	distance;

	ft_init_reshenie(stacks);
	while (stacks->size >= stacks->big && gen <= (stacks->generation + 1))
	{
		stacks->temp = ft_blizko_ingroup(stacks->stack_a, gen,
				stacks->gen_size);
		if (stacks->temp = NULL && ++gen)
			continue ;
		distance = ft_count_to_top(stacks->stack_a, stacks->temp->index);
		if (stacks->stack_a && ft_isswapable(stacks->stack_a))
		{
			ft_swap_a(stacks);
			stacks->big = ft_find_biggest_loop(stacks->stack_a, 1);
		}
		else if (stacks->stack_a && !stacks->stack_a->flag && distance == 0)
		{
			ft_push_b(stacks);
			(stacks->size)--;
		}
		else if (stacks->generation == 1)
			ft_rotate_b_a(stacks);
		else
			ft_rotate(stacks, ft_min(1, ft_max(-1, distance)));
	}
	ft_populate_b(stacks);
}
