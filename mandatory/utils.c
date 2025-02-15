#include "push_swap.h"

t_stack	*get_max(t_stack *b)
{
	t_stack	*max;

	max = b;
	b = b->next;
	while (b)
	{
		if (b->num > max->num)
			max = b;
		b = b->next;
	}
	return (max);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	if (!(*b))
	{
		pb(a, b);
	}
	else
	{
		if ((*b)->num > (*a)->num)
		{
			pb(a, b);
			(*b) = swap(*b, 0);
		}
		else
			pb(a, b);
	}
}

t_stack	*position(t_stack *a)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = a;
	while (current)
	{
		current->position = i;
		i++;
		current = current->next;
	}
	return (a);
}

t_stack	*indexing(t_stack *a)
{
	int		*num;
	t_stack	*tmp;

	int (i), (size);
	size = ft_stksize(a);
	tmp = a;
	i = 0;
	num = malloc(sizeof(int) * size);
	bubble_sort(a, num, size);
	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (a->num == num[i])
				a->index = i;
			i++;
		}
		a = a->next;
	}
	free(num);
	return (tmp);
}

void	bubble_sort(t_stack *a, int *num, int size)
{
	int (i), (max), (j);
	j = 0;
	while (j < size)
	{
		num[j++] = a->num;
		a = a->next;
	}
	j = 0;
	while (j < size)
	{
		i = 0;
		max = num[i++];
		while (i < size - j)
		{
			if (num[i] < max)
			{
				num[i - 1] = num[i];
				num[i] = max;
			}
			else
				max = num[i];
			i++;
		}
		j++;
	}
}
