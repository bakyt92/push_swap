/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:06:10 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/03/20 21:15:21 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void 	ft_double_rotate(s_allData *stacks, int *rot_a, int *rot_b)
{
	while (*rot_a > 0 && *rot_b > 0)
	{
		(*rot_a)--;
		(*rot_b)--;
		ft_rotate_b_a(stacks);
	}
	while (*rot_a < 0 && *rot_b < 0)
	{
		(*rot_a)++;
		(*rot_b)++;
		ft_reverse_rotate_b_a(stacks);
	}
}

void	ft_rotate(s_allData *stacks, int rot_a, int rot_b)
{
	ft_double_rotate(stacks, &rot_a, &rot_b);
	while (rot_a > 0)
	{
		rot_a--;
		ft_rotate_a(stacks);
	}
	while (rot_a < 0)
	{
		rot_a++;
		ft_reverse_rotate_a(stacks);
	}
	while (rot_b > 0)
	{
		rot_b--;
		ft_rotate_b(stacks);
	}
	while (rot_b < 0)
	{
		rot_b++;
		ft_reverse_rotate_b(stacks);
	}
}
