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

int	ft_hasvalue(s_list *l, int val)
{
	while (l)
	{
		if (l->value == val)
			return (1);
		l = l->next;
	}
	return (0);
}

void	push_stack(s_list **stack_a, int val, int tag, s_allData *stacks)
{
	s_list	*elem;
	s_list	*last_el;

//	last_el = NULL;
//	elem = NULL;
	last_el = *stack_a;
	if (ft_hasvalue(*stack_a, val))
		ft_error("Error\n", stacks);
	elem = malloc(sizeof(s_list));
	if (!elem)
		ft_error("Error\n", stacks);
	elem->next = NULL;
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
