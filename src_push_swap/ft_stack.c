/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:06:57 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/03/23 02:15:12 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_hasvalue(t_list *l, int val)
{
	while (l)
	{
		if (l->value == val)
			return (1);
		l = l->next;
	}
	return (0);
}

void	push_stack(t_list **stack_a, int val, int tag, t_allData *stacks)
{
	t_list	*elem;
	t_list	*begin;

	begin = *stack_a;
	/*проверка на дубликат, всем присваивается индекс -1*/
	if (ft_hasvalue(*stack_a, val))
		ft_error("Error\n", stacks);
	elem = malloc(sizeof(t_list));
	if (!elem)
		ft_error("Error\n", stacks);
	elem->next = NULL;
	elem->previous = NULL;
	elem->next_sorted = NULL;
	elem->value = val;
	elem->index = tag;
	if (!begin)
	{
		*stack_a = elem;
		return ;
	}
	else if (begin)
	{
		begin->next_sorted = elem;
		ft_push_front_lst(&begin, &elem);
	}

	/*
	while (last_el->next)
		last_el = last_el->next;
	last_el->next = elem;
	last_el->next_sorted = elem;
	 */
}

void	ft_push_front_lst(t_list **begin, t_list **elem)
{
	if (!(*begin)->previous)
	{
		(*begin)->previous = *elem;
		(*begin)->next = *elem;
		(*elem)->previous = *begin;
		(*elem)->next = *begin;
	}
	else
	{
		(*elem)->next = *begin;
		(*elem)->previous = (*begin)->previous;
		(*begin)->previous->next = *elem;
		(*begin)->previous = *elem;
	}

	/*
	t = *begin;
	(*)

	while (t)
		t = t->next;
	t->next = elem;
	(*elem)->previous = t;
	(*elem)->next = *begin;
	(*begin)->previous = elem;


	while (*begin)
		*begin = (*begin)->next;
	(*begin)->next = *elem;
	(*begin)->next_sorted = *elem;
	(*elem)->previous = *begin;
*/
}

int	ft_init_struct(t_allData **stacks, t_list **start)
{
	*stacks = malloc(sizeof(t_allData));
	if (!*stacks)
		return (0);
	*start = malloc(sizeof(t_list));
	if (!*start)
		return (0);
	(*stacks)->stack_a = NULL;
	(*stacks)->stack_b = NULL;
	return (1);
}
