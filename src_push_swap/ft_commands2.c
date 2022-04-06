/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:11:18 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/04/06 01:01:57 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_a(t_allData *stacks)
{
	int	size_stack;

	size_stack = ft_lst_size(stacks->stack_b);
	ft_push_top12(&(stacks->stack_b), &(stacks->stack_a));
	size_stack -= 1;
	if (size_stack == 0)
		stacks->stack_b = NULL;
	if (stacks->print)
		ft_putstr("pa");
}

void	ft_push_b(t_allData *stacks)
{
	int	size_stack;

	size_stack = ft_lst_size(stacks->stack_a);
	ft_push_top12(&(stacks->stack_a), &(stacks->stack_b));
	size_stack -= 1;
	if (size_stack == 0)
		stacks->stack_a = NULL;
	if (stacks->print)
		ft_putstr("pb");
}
