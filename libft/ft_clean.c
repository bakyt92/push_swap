/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:05:30 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/03/20 21:05:33 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_list(t_list **list)
{
	t_list	*t;
	t_list	*next;

	t = *list;
	while(t)
	{
		next = t->next;
		free(t);
		t = next;
	}
	*list = NULL;
}
