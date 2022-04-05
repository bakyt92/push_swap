/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:06:51 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/04/06 01:00:48 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*
void	ft_reshenie(t_allData *stacks, int gen)
{
	int	distance;

	ft_init_reshenie(stacks);
	while (stacks->size >= stacks->big && gen <= (stacks->generation + 1))
	{
		stacks->temp = ft_blizko_ingroup(stacks->stack_a, gen,
				stacks->gen_size);
		if (stacks->temp == NULL && ++gen)
			continue ;
		distance = ft_count_to_top(stacks->stack_a, stacks->temp->index);
		if (stacks->stack_a && ft_isswapable(stacks->stack_a))
		{
			ft_swap_a(stacks);
			stacks->big = ft_find_biggest_loop(stacks->stack_a, 1);
		}
		else if (stacks->stack_a && !stacks->stack_a->flag && distance == 0)
		{
			ft_push_b(stacks);
			(stacks->size)--;
		}
		else if (stacks->generation == 1)
			ft_rotate_b_a(stacks);
		else
			ft_rotate(stacks, ft_minimum(1, ft_maximum(-1, distance)), 0);
	}
	ft_populate_b(stacks);
}

void	ft_populate_b(t_allData *stacks)
{
	int	rot_a;
	int	rot_b;

	while (stacks->stack_b)
	{
		ft_calculate_b_rotation(stacks, stacks->max, &rot_a, &rot_b);
		ft_rotate(stacks, rot_a, rot_b);
		ft_push_a(stacks);
		(stacks->size)++;
	}
	ft_rotate(stacks, ft_count_to_top(stacks->stack_a, 0), 0);
}

void	ft_calculate_b_rotation(t_allData *stacks, int max_dist, int *rot_a,
								int *rot_b)
{
	int dist_total;
	int insert;
	int	distance_b;
	int	i;

	i = 0;
	stacks->temp = stacks->stack_b;
	while (stacks->temp)
	{
		distance_b = ft_count_to_index(i++, stacks->max - stacks->size);
		insert = ft_insert_distance(stacks->stack_a, stacks->temp->index,
									stacks->size);
		dist_total = ft_positive(insert) + ft_positive(distance_b);
		if (insert > 0 && distance_b > 0)
			dist_total = dist_total - ft_minimum(distance_b, insert);
		if (insert > 0 && distance_b > 0)
			dist_total = dist_total + ft_maximum(distance_b, insert);
		if (dist_total < max_dist)
		{
			max_dist = dist_total;
			*rot_a = insert;
			*rot_b = distance_b;
		}
		stacks->temp = stacks->temp->next;
	}
}
*/
int ft_count_to_index(int index, int size)
{
	if (index >= size / 2)
		index = size - index;
	return (index);
}

int	ft_insert_distance(t_list *list, int t, int size)
{
	t_list	*p;
	t_list	*c;
	int		c_max[2];
	int		i;

	i = 0;
	p = ft_get_last(list);
	c = list;
	c_max[1] = size;
	while (c)
	{
		if ((p->index > c->index && (t < c->index || t > p->index))
		|| (t > p->index && t < c->index))
		{
			c_max[0] = i;
			if (c_max[0] > size / 2)
				c_max[0] -= size;
			if (ft_positive(c_max[0]) < c_max[1])
				c_max[1] = c_max[0];
		}
		p = c;
		c = c->next;
		i++;
	}
	return (c_max[1]);
}
