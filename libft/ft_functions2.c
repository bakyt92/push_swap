#include "../push_swap.h"

int	ft_lst_size(s_list *t)
{
	int i;

	i = 0;
	while (t)
	{
		i++;
		t = t->next;
	}
	return (i);
}

int	ft_positive(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}