#ifndef INC_05_1_PUSH_SWAP_PUSH_SWAP_H
#define INC_05_1_PUSH_SWAP_PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct t_list {
	int value;
	int	index;
	int generation;
	int flag; /*зачем эта переменная???*/
	struct t_list *next;
	struct t_list *prev;
} s_list;

typedef struct t_allData {
	s_list *stack_a;
	s_list *stack_b;
	int median;
	int size_a;
	int size_b;
	int min;
	int max;
} s_allData;

char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		check_arg(char *str);
void	ft_error (char *str, s_allData *stacks);
void	ft_free_list(s_list **list);
int		ft_isdigit(int c);
void	read_arguments(int argc, char **argv, s_allData *stacks);
/* ft_stack */
void	push_stack(s_list **stack, int val, int tag, s_allData *stacks);
int	ft_hasvalue(s_list *l, int val);

/* ft_functions 1-3 */
int ft_atoi(char *str, s_allData *stacks);

#endif
