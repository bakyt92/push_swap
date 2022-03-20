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
	int		median;
	int		size;
	int		big;
	int		min;
	int		max;
} s_allData;

char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		check_arg(char *str);
void	ft_error (char *str, s_allData *stacks);
void	ft_free_list(s_list **list);
int		ft_isdigit(int c);

/* ft_stack */
void	push_stack(s_list **stack, int val, int tag, s_allData *stacks);
int		ft_hasvalue(s_list *l, int val);

/* ft_functions 1-3 */
int		ft_atoi(char *str, s_allData *stacks);
int		ft_ordered(s_allData *stacks);
void	ft_sw_list(s_list **pred, s_list *last);
int		ft_lst_size(s_list *t);
int		ft_positive(int a);

/* file push_swap */
void	ft_sorting(s_list **stacks);
void	read_arguments(int argc, char **argv, s_allData *stacks);

/* ft_sort 1-2 */
void	ft_indexing(s_list *start, s_allData *stacks);
void	ft_5args(s_allData *stacks);
int		ft_count_to_top(s_list *t, int index);
int		ft_has_index(s_list *t, int index);
void	ft_reshenie(s_allData *stacks, int gen);

/* ft_sort_utils */
s_list	*ft_blizko_ingroup (s_list *tmp, int gen, int generation_size);
int 	ft_isswapable(s_list *tmp);
int 	ft_find_biggest_loop(s_list *begin, int number);
int		ft_make_loop(s_list *tmp, s_list *begin, int number);
void 	ft_init_reshenie(s_allData *stacks);

/* ft_commands */
void	ft_rotate(s_allData *stacks, int rot_a, int rot_b);

#endif
