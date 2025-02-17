/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:24:50 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/02/17 21:24:53 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	line_error(char *line, t_stack **a)
{
	if (!line)
	{
		if (!sorted(*a))
			errors("KO", a);
		else
			errors("OK", a);
	}
}

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] == ' ')
		i++;
	return (str[i] == '\0');
}

void	ft_stkclear(t_stack **a)
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
}

int	main(int ac, char **av)
{
	t_stack	*a;
	int		*num;
	int		size;
	char	**instructions;

	size = 0;
	if (ac == 1)
		return (0);
	num = add(ac, av, &size);
	a = push_stack(num, size);
	free(num);
	instructions = read_instructions(&a);
	execute_instructions(&a, instructions);
}
