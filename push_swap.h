#ifndef INC_05_1_PUSH_SWAP_PUSH_SWAP_H
#define INC_05_1_PUSH_SWAP_PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct t_node {
	int value;
	int	index;
	int generation;
	int flag; /*зачем эта переменная???*/
	struct t_node *next;
	struct t_node *prev;
} s_Node;

typedef struct t_allData {
	s_Node *stack_a;
	s_Node *stack_b;
	int median;
	int size_a;
	int size_b;
	int min;
	int max;
} s_allData;

char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);


#endif
