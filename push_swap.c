/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:07:12 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/03/27 21:30:10 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting(t_list **stacks)
{
	t_list	*last;
	t_list	*pred;

	pred = NULL;
	last = *stacks;
	while (last && last->next_sorted)
	{
		if (last->value - last->next_sorted->value > 0)
		{
			if (pred == NULL)
				ft_sw_list(stacks, last);
			else
				ft_sw_list(&(pred->next_sorted), last);
			last = *stacks;
			pred = NULL;
		}
		else
		{
			pred = last;
			last = last->next_sorted;
		}
	}
}

char	*read_line(int i, char **argv)
{
	char	*line;
	int		j;

	j = 0;
	line = ft_strdup("");
	while (argv[i])
	{
		line = ft_strjoin(line, &argv[i][j]);
		i++;
	}
	return (line);
}

void	read_arguments(int argc, char **argv, t_allData *stacks)
{
	int	i;
	int	j;
	int	space_1;

	i = 1;
	while (i < argc)
	{
		j = 0;
		space_1 = 1;
		if (!check_arg(argv[i]))
			ft_error("Error\n", stacks);
		while (argv[i][j])
		{
			if (argv[i][j] != '+' && argv[i][j] != '-' && argv[i][j] != ' ' &&
			!ft_isdigit(argv[i][j]))
				ft_error("Error\n", stacks);
			if (space_1 == 1 && argv[i][j] != ' ')
			{
				push_stack(&(stacks->stack_a), ft_atoi(argv[i] + j,
						stacks), -1, stacks);
				space_1 = 0;
			}
			space_1 = argv[i][j] == ' ';
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_allData	*stacks;
	t_list		*start;
	
	stacks = malloc(sizeof(t_allData));
	if (!stacks)
		return (0);
	start = malloc(sizeof(t_list));
	if (!start)
		return (0);
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	if (argc < 2)
	{
		return (0);
	}
	read_arguments(argc, argv, stacks);
	if (!ft_ordered(stacks))
	{
		start = stacks->stack_a;
		ft_sorting(&start);
		ft_indexing(start, stacks);
		if (stacks->max == 5)
			ft_5args(stacks);
		ft_reshenie(stacks, 1);
	}
	/* CLEAR ALL добавить */
	start = NULL;
	return (0);
}
