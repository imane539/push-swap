#include "push_swap_bonus.h"

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*b))
	{
		(*b) = (*a);
		(*a) = (*a)->next;
		(*b)->next = NULL;
	}
	else
	{
		tmp = (*b);
		(*b) = (*a);
		(*a) = (*a)->next;
		(*b)->next = tmp;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	if(!ft_stksize(*a) || !ft_stksize(*b))
		return ;
	if (!(*a))
	{
		(*a) = (*b);
		(*b) = (*b)->next;
		(*a)->next = NULL;
	}
	else
	{
		tmp = (*a);
		(*a) = (*b);
		(*b) = (*b)->next;
		(*a)->next = tmp;
	}
}

t_stack	*swap(t_stack *a)
{
	t_stack	*tmp;
	if(!a)
	return a;
	if (ft_stksize(a) == 1)
		return (a);
	tmp = a;
	a = a->next;
	tmp->next = a->next;
	a->next = tmp;
	return (a);
}

t_stack	*rotate(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!a)
		return (a);
	last = ft_stklast(a);
	tmp = a;
	a = a->next;
	last->next = tmp;
	tmp->next = NULL;
	return (a);
}

t_stack	*reverse_rotate(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!a)
		return (a);
	tmp = a;
	last = a;
	a = ft_stklast(a);
	while (last->next->next)
		last = last->next;
	a->next = tmp;
	last->next = NULL;
	return (a);
}
