#include "../push_swap.h"



void	ft_rotate(s_allData *stacks, int rot_a, int rot_b)
{
	ft_double_rotate(stacks, &rot_a, &rot_b)
	while (rot_a > 0)
	{
		rot_a--;
		ft_rotate_a(stacks);
	}
	while (rot_a < 0)
	{
		rot_a++;
		ft_rev_rotate_a(stacks);
	}
	while (rot_b > 0)
	{
		rot_b--;
		ft_rotate_b(stacks);
	}
	while (rot_b < 0)
	{
		rot_b++;
		ft_rev_rotate_b(stacks);
	}
}