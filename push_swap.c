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
		line = ft_strjoin(line, argv[i][j]);
		j++;
	}
	return (line);
}

void	read_args(int argc, char **argv, s_allData *stacks)
{
	int i;
	char *array;

	array = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		if(!check_arg(argv[i]))
			ft_error("Error\n");


	}
}

int main(int argc, char **argv)
{
	s_allData *stacks;

	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	if (argc < 2)
		return (0);
	else
		read_args(argc, argv, &stacks);




	{

		sort(stacks);
		free_stack(stacks);
	}
	return 0;
}

