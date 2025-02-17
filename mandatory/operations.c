/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:23:14 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/02/17 21:23:17 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putstr_fd("pb\n", 1);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

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
	ft_putstr_fd("pa\n", 1);
}

t_stack	*swap(t_stack *a, int check)
{
	t_stack	*tmp;

	tmp = a;
	a = a->next;
	tmp->next = a->next;
	a->next = tmp;
	if (check == 1)
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
	return (a);
}

t_stack	*rotate(t_stack *a, int check)
{
	t_stack	*tmp;
	t_stack	*last;

	last = ft_stklast(a);
	tmp = a;
	a = a->next;
	last->next = tmp;
	tmp->next = NULL;
	if (check == 1)
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
	return (a);
}

t_stack	*reverse_rotate(t_stack *a, int check)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = a;
	last = a;
	a = ft_stklast(a);
	while (last->next->next)
		last = last->next;
	a->next = tmp;
	last->next = NULL;
	if (check == 1)
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
	return (a);
}
