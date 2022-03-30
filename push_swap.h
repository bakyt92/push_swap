/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:36:38 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/03/27 21:44:35 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_list {
	int				value;
	int				index;
	int				flag;
	struct t_list	*next;
	struct t_list	*previous;
	struct t_list	*next_sorted;
}					t_list;

typedef struct s_allData {
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*temp;
	int		generation;
	int		gen_size;
	int		size;
	int		big;
	int		max;
	int		print;
}			t_allData;

/* ft_libft  */
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);

/* ft_arg */
int		ft_isdigit(int c);
void	ft_putstr(char *str);
int		check_arg(char *str);
void	ft_error(char *str, t_allData *stacks);

/* ft_clean */
void	ft_free_list(t_list **list);

/* ft_stack */
void	push_stack(t_list **stack, int val, int tag, t_allData *stacks);
int		ft_hasvalue(t_list *l, int val);
int		ft_init_struct(t_allData **stacks, t_list **start);
void	ft_push_front_lst(t_list **begin, t_list **elem);

/* ft_functions 1-3 */
int		ft_atoi(char *str, t_allData *stacks);
int		ft_ordered(t_allData *stacks);
void	ft_sw_list(t_list **pred, t_list *last);
int		ft_lst_size(t_list *t);
int		ft_positive(int a);
int		ft_maximum(int a, int b);
int		ft_minimum(int a, int b);
t_list	*ft_get_last(t_list *t);

/* file push_swap */
void	ft_sorting(t_list **stacks);
void	read_arguments(int argc, char **argv, t_allData *stacks);

/* ft_sort 1-2 */
void	ft_indexing(t_list *start, t_allData *stacks);
void	ft_5args(t_allData *stacks);
int		ft_count_to_top(t_list *t, int index);
int		ft_has_index(t_list *t, int index);
void	ft_reshenie(t_allData *stacks, int gen);
void	ft_populate_b(t_allData *stacks);
int		ft_count_to_index(int index, int size);
void	ft_calculate_b_rotation(t_allData *stacks, int max_dist, int *rot_a,
								int *rot_b);
int		ft_insert_distance(t_list *list, int t, int size);

/* ft_sort_utils */
t_list	*ft_blizko_ingroup(t_list *tmp, int gen, int generation_size);
int		ft_isswapable(t_list *tmp);
int		ft_find_biggest_loop(t_list *begin, int number);
int		ft_make_loop(t_list *tmp, t_list *begin, int number);
void	ft_init_reshenie(t_allData *stacks);

/* ft_commands */
void	ft_rotate(t_allData *stacks, int rot_a, int rot_b);
void	ft_double_rotate(t_allData *stacks, int *rot_a, int *rot_b);
void	ft_swap_a(t_allData *stacks);
void	ft_swap_b(t_allData *stacks);
void	ft_swap_b_a(t_allData *stacks);
void	ft_push_a(t_allData *stacks);
void	ft_push_b(t_allData *stacks);
void	ft_reverse_rotate_a(t_allData *stacks);
void	ft_reverse_rotate_b(t_allData *stacks);
void	ft_reverse_rotate_b_a(t_allData *stacks);
void	ft_rotate_a(t_allData *stacks);
void	ft_rotate_b(t_allData *stacks);
void	ft_rotate_b_a(t_allData *stacks);
void	ft_swap_lst(t_list *stacks);
void	ft_push_top12(t_list *place1, t_list *place2);
void	ft_push_bottom(t_list *t);
void	ft_push_top(t_list *t);

#endif
