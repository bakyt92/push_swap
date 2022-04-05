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

	/* пример Марат
	t_list	*second_element;
	t_list	*third_element;

	if (!*stacks || !(*stacks)->next)
		return ;
	second_element = (*stacks)->next;
	if (second_element->next)
		third_element = second_element->next;
	else
		third_element = *stacks;
	second_element->next = *stacks;
	second_element->previous = (*stacks)->previous;
	(*stacks)->next = third_element;
	(*stacks)->previous = second_element;
	 */
	/*
	head = (*stacks);
	second_element = (*stacks)->next;
	(*stacks)->next->next = second_element->next;
	(*stacks)->next = head;
	(*stacks)->previous->next = second_element;
	(*stacks)->previous = head->previous;
	(*stacks) = second_element;
*/
	/*
	add_element = (*stacks)->next->next;
	tmp = *stacks;
	stacks = (*stacks)->next;
	(*stacks)->next = tmp;
	tmp->next = add_element;
 */
}

/* точно не надо поменять функцию эту */
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
	/*
	if (!*place1)
		return ;
	top = *place1;
	*place1 = top->next;
	if (*place2)
		top->next = *place2;
	else
		top->next = NULL;
	*place2 = top;
	 */
}

void	ft_push_bottom(t_list **t)
{
//	t_list	*top;
//	t_list	*tmp;

	if (!*t || !(*t)->next)
		return ;
//	top = t;
	*t = (*t)->next;

	/*
	t = t->next;
	tmp = t;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (t == tmp)
			break ;
	}
	tmp->next = top;
	top->next = NULL;
	*/
}

void	ft_push_top(t_list **t)
{
//	t_list	*tmp;
//	t_list	*last;

	if (!*t || !(*t)->next)
		return ;
//	last = t;
	*t = (*t)->previous;
	/*
	last = t->previous;
	last->previous = t->previous->previous;
	last = t->next;
	t = last->next;

	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = t;
	t = last;
	tmp->next = NULL;
	 */
}
