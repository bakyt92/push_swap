#ifndef INC_05_1_PUSH_SWAP_PUSH_SWAP_H
#define INC_05_1_PUSH_SWAP_PUSH_SWAP_H

#include <stdio.h>

typedef struct t_node {
	int value;
	int	order_sort;
	int generation;
	struct t_node *next;
	struct t_node *prev;
} s_Node;

typedef struct t_process {
	int x;
	int y;
} s_process;

#endif
