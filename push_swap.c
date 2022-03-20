#include "push_swap.h"

void	ft_sorting(s_list **stacks)
{
	s_list	*last;
	s_list	*pred;

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

void	free_stack(s_allData *stacks)
{

}

char	*read_line(int i, char **argv)
{
	char *line;
	int j;

	j = 0;
	line = ft_strdup("");
	while(argv[i])
	{
		line = ft_strjoin(line, &argv[i][j]);
		i++;
	}
	return (line);
}

void	read_arguments(int argc, char **argv, s_allData *stacks)
{
	int i;
	int j;
	int space_1;

	i = 1;
	while (i < argc)
	{
		j = 0;
		space_1 = 1;
		if(!check_arg(argv[i]))
			ft_error("Error\n", stacks);
		while(argv[i][j])
		{
			if(argv[i][j] != '+' && argv[i][j] != '-' && argv[i][j] != ' ' &&
			!ft_isdigit(argv[i][j]))
				ft_error("Error\n", stacks);
			if (space_1 == 1 && argv[i][j] != ' ')
			{
				push_stack(&(stacks->stack_a), ft_atoi(argv[i] + j, stacks),
						   -1,stacks);
				space_1 = 0;
			}
			space_1 = argv[i][j] == ' ';
			j++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	s_allData	*stacks;
	s_list		*start;

	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	if (argc < 2)
		return (0);
	read_arguments(argc, argv, stacks);
	if (!ft_ordered(stacks))
	{
		start = stacks->stack_a;
		ft_sorting(&start);
		ft_indexing(start, stacks);
		if (stacks->max == 5)
			ft_5args(stacks);
		ft_reshenie(&stacks, 1);
	}
	/* CLEAR ALL добавить */
	start = NULL;
	return (0);
}