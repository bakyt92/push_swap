#include "push_swap.h"

void	sort(s_allData *stacks)
{

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
	s_allData *stacks;

	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	if (argc < 2)
		return (0);
	read_arguments(argc, argv, stacks);
	if (ft_ordered(stacks))
	{

	}
	return 0;
}