/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:06:10 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/03/23 02:13:07 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_a(t_allData *stacks)
{
	ft_swap_lst(&(stacks->stack_a));
	if (stacks->print)
		ft_putstr("sa");
}

void	ft_swap_b(t_allData *stacks)
{
	ft_swap_lst(&(stacks->stack_b));
	if (stacks->print)
		ft_putstr("sb");
}

void	ft_swap_b_a(t_allData *stacks)
{
	ft_swap_lst(&(stacks->stack_a));
	ft_swap_lst(&(stacks->stack_b));
	if (stacks->print)
		ft_putstr("ss");
}
