#include "../push_swap.h"

void	ft_free_list(s_list **list)
{
	s_list	*t;
	s_list	*next;

	t = *list;
	while(t)
	{
		next = t->next;
		free(t);
		t = next;
	}
	*list = NULL;
}
