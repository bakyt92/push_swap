/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:07:20 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/03/20 21:07:22 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_05_1_PUSH_SWAP_PUSH_SWAP_H
#define INC_05_1_PUSH_SWAP_PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct t_list {
	int		value;
	int		index;
	int		flag;
	struct	t_list *next;
	struct	t_list *next_sorted;
} 			s_list;

typedef struct t_allData {
	s_list	*stack_a;
	s_list	*stack_b;
	s_list	*temp;
	int		generation;
	int		gen_size;
//	int		median;
	int		size;
	int		big;
//	int		min;
	int		max;
	int		print;
} s_allData;

/* ft_libft  */
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int 	ft_strlen(const char *str);

/* ft_arg */
int		ft_isdigit(int c);
void	ft_putstr(char *str);
int		check_arg(char *str);
void	ft_error (char *str, s_allData *stacks);

/* ft_clean */
void	ft_free_list(s_list **list);

/* ft_stack */
void	push_stack(s_list **stack, int val, int tag, s_allData *stacks);
int		ft_hasvalue(s_list *l, int val);

/* ft_functions 1-3 */
int		ft_atoi(char *str, s_allData *stacks);
int		ft_ordered(s_allData *stacks);
void	ft_sw_list(s_list **pred, s_list *last);
int		ft_lst_size(s_list *t);
int		ft_positive(int a);
int		ft_maximum(int a, int b);
int		ft_minimum(int a, int b);
s_list	*ft_get_last(s_list *t);

/* file push_swap */
void	ft_sorting(s_list **stacks);
void	read_arguments(int argc, char **argv, s_allData *stacks);

/* ft_sort 1-2 */
void	ft_indexing(s_list *start, s_allData *stacks);
void	ft_5args(s_allData *stacks);
int		ft_count_to_top(s_list *t, int index);
int		ft_has_index(s_list *t, int index);
void	ft_reshenie(s_allData *stacks, int gen);
void	ft_populate_b(s_allData *stacks);
int		ft_count_to_index(int index, int size);
void	ft_calculate_b_rotation(s_allData *stacks, int max_dist, int *rot_a,
								int *rot_b);
int		ft_insert_distance(s_list *list, int t, int size);

/* ft_sort_utils */
s_list	*ft_blizko_ingroup (s_list *tmp, int gen, int generation_size);
int 	ft_isswapable(s_list *tmp);
int 	ft_find_biggest_loop(s_list *begin, int number);
int		ft_make_loop(s_list *tmp, s_list *begin, int number);
void 	ft_init_reshenie(s_allData *stacks);

/* ft_commands */
void	ft_rotate(s_allData *stacks, int rot_a, int rot_b);
void 	ft_double_rotate(s_allData *stacks, int *rot_a, int *rot_b);
void	ft_swap_a(s_allData *stacks);
void	ft_swap_b(s_allData *stacks);
void	ft_swap_b_a(s_allData *stacks);
void	ft_push_a(s_allData *stacks);
void	ft_push_b(s_allData *stacks);
void	ft_reverse_rotate_a(s_allData *stacks);
void	ft_reverse_rotate_b(s_allData *stacks);
void	ft_reverse_rotate_b_a(s_allData *stacks);
void	ft_rotate_a(s_allData *stacks);
void	ft_rotate_b(s_allData *stacks);
void	ft_rotate_b_a(s_allData *stacks);
void	ft_swap_lst(s_list *stacks);
void	ft_push_top12(s_list *place1, s_list *place2);
void	ft_push_bottom(s_list *t);
void	ft_push_top(s_list *t);

#endif
