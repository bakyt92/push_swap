/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:11:18 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/03/23 02:11:20 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_a(t_allData *stacks)
{
	ft_swap_lst(stacks->stack_a);
	if (stacks->print)
		ft_putstr("sa");
}

void	ft_swap_b(t_allData *stacks)
{
	ft_swap_lst(stacks->stack_b);
	if (stacks->print)
		ft_putstr("sb");
}

void	ft_swap_b_a(t_allData *stacks)
{
	ft_swap_lst(stacks->stack_a);
	ft_swap_lst(stacks->stack_b);
	if (stacks->print)
		ft_putstr("ss");
}

void	ft_push_a(t_allData *stacks)
{
	ft_push_top12(stacks->stack_b, stacks->stack_a);
	if (stacks->print)
		ft_putstr("pa");
}

void	ft_push_b(t_allData *stacks)
{
	ft_push_top12(stacks->stack_a, stacks->stack_b);
	if (stacks->print)
		ft_putstr("pb");
}
