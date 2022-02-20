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
	while(argv[i][j])
	{
		line = ft_strjoin(line, argv[i][j]);
		j++;
	}
	return (line);
}

s_allData	*read_args(int argc, char **argv)
{
	int i;
	char *array;

	array = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		array = ft_strjoin(array, read_line(i, argv));
		i++;
	}
	ft_process(array);
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

