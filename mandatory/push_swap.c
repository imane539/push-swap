/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:23:37 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/02/17 21:23:39 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] == ' ')
		i++;
	return (str[i] == '\0');
}

void	ft_sktclear(t_stack **a)
{
	t_stack	*tmp;

	if (!a)
		return ;
	while (*a)
	{
		tmp = *a;
		(*a) = (*a)->next;
		free(tmp);
	}
	*a = NULL;
	exit(0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	int		*num;
	int		size;

	size = 0;
	if (ac == 1)
		return (0);
	num = add(ac, av, &size);
	if (size == 0)
		ft_error(num, NULL);
	a = push_stack(num, size);
	free(num);
	if (sorted(a) == 1 || size == 1)
		ft_sktclear(&a);
	if (size == 2)
	{
		a = swap(a, 1);
		ft_sktclear(&a);
	}
	if (size < 6)
	{
		sort_5(&a, size);
		ft_sktclear(&a);
	}
	sort_large(&a, size);
}
