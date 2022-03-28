/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:11:24 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/03/23 02:11:27 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse_rotate_a(t_allData *stacks)
{
	ft_push_top(stacks->stack_a);
	if (stacks->print)
		ft_putstr("rra");
}

void	ft_reverse_rotate_b(t_allData *stacks)
{
	ft_push_top(stacks->stack_b);
	if (stacks->print)
		ft_putstr("rrb");
}

void	ft_reverse_rotate_b_a(t_allData *stacks)
{
	ft_push_top(stacks->stack_b);
	ft_push_top(stacks->stack_a);
	if (stacks->print)
		ft_putstr("rrr");
}

void	ft_rotate_a(t_allData *stacks)
{
	ft_push_bottom(stacks->stack_a);
	if (stacks->print)
		ft_putstr("ra");
}

void	ft_rotate_b(t_allData *stacks)
{
	ft_push_bottom(stacks->stack_b);
	if (stacks->print)
		ft_putstr("rb");
}
