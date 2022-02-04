#include "push_swap.h"

void	sort(s_allData *stacks)
{

}

void	free_stack(s_allData *stacks)
{

}

s_allData	*read_args(int argc, char **argv)
{

}

int main(int argc, char **argv)
{
	s_allData *stacks;

	stacks->stack_a = NULL;
	stacks->stack_b = NULL;

	if (argc < 2)
		return (0);
	else
	{
		stacks = read_args(argc, argv);
		sort(stacks);
		free_stack(stacks);
	}
	return 0;
}

