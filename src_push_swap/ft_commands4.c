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
	ft_push_bottom(stacks->stack_a);
	ft_push_bottom(stacks->stack_b);
	if (stacks->print)
		ft_putstr("rr");
}

void	ft_swap_lst(t_list *stacks)
{
	t_list	*tmp;
	t_list	*add_element;

	if (!stacks || !stacks->next)
		return ;
	add_element = stacks->next->next;
	tmp = stacks;
	stacks = stacks->next;
	stacks->next = tmp;
	tmp->next = add_element;
}

void	ft_push_top12(t_list *place1, t_list *place2)
{
	t_list	*top;

	if (!place1)
		return ;
	top = place1;
	place1 = top->next;
	if (place2)
		top->next = place2;
	else
		top->next = NULL;
	place2 = top;
}

void	ft_push_bottom(t_list *t)
{
	t_list	*top;
	t_list	*tmp;

	if (!t || !t->next)
		return ;
	top = t;
	t = t->next;
	tmp = t;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = top;
	top->next = NULL;
}

void	ft_push_top(t_list *t)
{
	t_list	*tmp;
	t_list	*last;

	if (!t || !t->next)
		return ;
	last = t;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = t;
	t = last;
	tmp->next = NULL;
}
