#include "../push_swap.h"

void	read_arguments(int argc, char **argv, t_allData *stacks)
{
	int	i;
	int	j;
	int	space_1;

	i = 1;
	while (i < argc)
	{
		j = 0;
		space_1 = 1;
		if (!check_arg(argv[i]))
			ft_error("Error\n", stacks);
		while (argv[i][j])
		{
			if (argv[i][j] != '+' && argv[i][j] != '-' && argv[i][j] != ' ' &&
				!ft_isdigit(argv[i][j]))
				ft_error("Error\n", stacks);
			if (space_1 == 1 && argv[i][j] != ' ')
			{
				push_stack(&(stacks->stack_a), ft_atoi(argv[i] + j,
													   stacks), -1, stacks);
				space_1 = 0;
			}
			space_1 = argv[i][j] == ' ';
			j++;
		}
		i++;
	}
}