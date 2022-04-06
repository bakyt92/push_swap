/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:57:19 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/04/06 00:58:02 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && i < n && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_execute_command(char *str, t_allData **stacks)
{
	if (!ft_strncmp(str, "sa\n", 3))
		ft_swap_a(*stacks);
	else if (!ft_strncmp(str, "sb\n", 3))
		ft_swap_b(*stacks);
	else if (!ft_strncmp(str, "ss\n", 3))
		ft_swap_b_a(*stacks);
	else if (!ft_strncmp(str, "pa\n", 3))
		ft_push_a(*stacks);
	else if (!ft_strncmp(str, "pb\n", 3))
		ft_push_b(*stacks);
	else if (!ft_strncmp(str, "ra\n", 3))
		ft_rotate_a(*stacks);
	else if (!ft_strncmp(str, "rb\n", 3))
		ft_rotate_b(*stacks);
	else if (!ft_strncmp(str, "rr\n", 3))
		ft_rotate_b_a(*stacks);
	else if (!ft_strncmp(str, "rra\n", 4))
		ft_reverse_rotate_a(*stacks);
	else if (!ft_strncmp(str, "rrb\n", 4))
		ft_reverse_rotate_b(*stacks);
	else if (!ft_strncmp(str, "rrr\n", 4))
		ft_reverse_rotate_b_a(*stacks);
	else
		ft_error("Error\n", *stacks);
}

int	main(int argc, char **argv)
{
	t_allData	*stacks;
	char		*str;

	if (argc < 2 || !ft_init_struct(&stacks))
		return (0);
	read_arguments(argc, argv, stacks);
	stacks->print = 0;
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		ft_execute_command(str, &stacks);
		free(str);
	}
	if (ft_ordered(stacks) && stacks->stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (stacks->stack_a)
		ft_free_list(&(stacks->stack_a));
	if (stacks->stack_b)
		ft_free_list(&(stacks->stack_b));
	free(stacks);
	return (0);
}
