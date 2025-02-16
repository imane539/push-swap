#include "push_swap_bonus.h"

int	ft_stksize(t_stack *a)
{
	int		i;
	t_stack	*current;

	i = 0;
	if (!a)
		return (i);
	current = a;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

t_stack	*ft_stknew(int num)
{
	t_stack	*p;

	p = NULL;
	p = malloc(sizeof(t_stack));
	if (!p)
		return (NULL);
	p->num = num;
	p->next = NULL;
	return (p);
}

t_stack	*ft_stklast(t_stack *stack)
{
	if (!stack)
		return (stack);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

t_stack	*push_stack(int *num, int size)
{
	t_stack	*head;
	t_stack	*last;
	t_stack	*new;
	int		i;

	i = 0;
	head = NULL;
	while (i < size)
	{
		new = ft_stknew(num[i]);
		if (!(head))
		{
			head = new;
		}
		else
		{
			last = ft_stklast(head);
			last->next = new;
		}
		i++;
	}
	return (head);
}

int	*add(int ac, char **av, int *size)
{
	int	*num;

	int (j), (sum), (error);
	error = 0;
	j = 0;
	sum = countword(&ac, av) + (ac - 1);
	num = malloc(sum * sizeof(int));
	if (!num)
		exit(1);
	while ((*size) < sum)
	{
		if(ft_strlen(av[j + 1]) == 0 || av[j + 1][0] == ' ')
				ft_error(num);
		if (ft_strchr(av[j + 1], ' '))
			num = space(num, av[j + 1], size);
		else
		{
			num[*size] = ft_atoi(av[j + 1], &error);
			if (error == 1 || duplicated(num, num[*size], *size) == 1)
				ft_error(num);
			(*size)++;
		}
		j++;
	}
	return (num);
}
