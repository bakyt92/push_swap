/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:58:22 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/04/06 00:58:25 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../push_swap.h"
# include "get_next_line.h"

void	ft_execute_command(char *str, t_allData **stacks);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
