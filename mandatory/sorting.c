#include "push_swap.h"

void	sort_large(t_stack **a, int size)
{
	int		range;
	t_stack	**b;

	if (size > 400)
		range = 35;
	else
		range = 16;
	b = fill_b(a, range);
	a = fill_a(a, b);
	free(b);
	ft_sktclear(a);
}

void	sort_3(t_stack **a)
{
	if ((*a)->index == 0)
	{
		(*a) = swap(*a, 1);
		(*a) = rotate(*a, 1);
	}
	else if ((*a)->index == 1)
	{
		if ((*a)->next->index == 0)
			(*a) = swap(*a, 1);
		else
			(*a) = reverse_rotate(*a, 1);
	}
	else
	{
		if ((*a)->next->index == 0)
			(*a) = rotate(*a, 1);
		else
		{
			(*a) = swap(*a, 1);
			(*a) = reverse_rotate(*a, 1);
		}
	}
}

void	sort_5(t_stack **a, int size)
{
	t_stack	**b;

	b = NULL;
	(*a) = indexing(*a);
	if (size == 3)
	{
		sort_3(a);
		return ;
	}
	else
	{
		b = malloc(sizeof(t_stack *));
		(*b) = NULL;
		push_two(a, b);
		if (!sorted(*a))
			sort_3(a);
		while (*b)
			pa(a, b);
		free(b);
	}
}
