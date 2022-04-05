/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:11:35 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/03/23 02:14:03 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate_b_a(t_allData *stacks)
{
	ft_push_bottom(&(stacks->stack_a));
	ft_push_bottom(&(stacks->stack_b));
	if (stacks->print)
		ft_putstr("rr");
}

void	ft_swap_lst(t_list **stacks)
{
	t_list	*second_elem;

	second_elem = (*stacks)->next;
	(*stacks)->next = (*stacks)->next->next;
	(*stacks)->next->previous = *stacks;
	second_elem->next = *stacks;
	second_elem->previous = (*stacks)->previous;
	(*stacks)->previous->next = second_elem;
	(*stacks)->previous = second_elem;
	(*stacks) = second_elem;

}

void	ft_push_top12(t_list **place1, t_list **place2)
{
	t_list	*top1;

	if (!*place1)
		return ;
	top1 = (*place1)->next;
	(*place1)->previous->next = (*place1)->next;
	(*place1)->next->previous = (*place1)->previous;
	if (*place2)
	{
		(*place1)->next = *place2;
		(*place1)->previous = (*place2)->previous;
		*place2 = *place1;
		(*place2)->next->previous = *place2;
		(*place2)->previous->next = *place2;
	}
	else
	{
		(*place1)->next = *place1;
		(*place1)->previous = *place1;
		*place2 = *place1;
	}
	(*place1) = top1;
}

void	ft_push_bottom(t_list **t)
{
	if (!*t || !(*t)->next)
		return ;
	*t = (*t)->next;
}

void	ft_push_top(t_list **t)
{
	if (!*t || !(*t)->next)
		return ;
	*t = (*t)->previous;
}
