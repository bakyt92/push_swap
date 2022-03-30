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
	t_list	*last_el;

	last_el = *stack_a;
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
	if (last_el == NULL)
	{
		*stack_a = elem;
		return ;
	}
	while (last_el->next)
		last_el = last_el->next;
	last_el->next = elem;
	last_el->next_sorted = elem;
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
