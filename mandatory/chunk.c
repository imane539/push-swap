#include "push_swap.h"

void	push_two(t_stack **a, t_stack **b)
{
	while (ft_stksize(*a) != 3)
	{
		if ((*a)->index == 0)
		{
			pb(a, b);
			(*a) = indexing(*a);
		}
		else if ((*a)->next->index == 0)
			(*a) = swap(*a, 1);
		else
			(*a) = rotate(*a, 1);
	}
}

t_stack	**fill_b(t_stack **a, int range)
{
	t_stack	**b;
	int		i;

	i = 0;
	(*a) = position(*a);
	b = malloc(sizeof(t_stack *));
	(*b) = NULL;
	while (ft_stksize(*a) != 0)
	{
		if ((*a)->index < i)
		{
			pb(a, b);
			(*b) = rotate(*b, 0);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			push_to_b(a, b);
			i++;
		}
		else
			(*a) = rotate(*a, 1);
		// (*a)=indexing(*a);
	}
	return (b);
}

t_stack	**fill_a(t_stack **a, t_stack **b)
{
	t_stack	*max;
	int		size;

	while (*b)
	{
		size = ft_stksize(*b);
		(*b) = position(*b);
		max = get_max(*b);
		if ((*b) == max)
			pa(a, b);
		else
		{
			if (max->position <= size / 2)
				(*b) = rotate(*b, 0);
			else
				(*b) = reverse_rotate(*b, 0);
		}
	}
	return (a);
}
