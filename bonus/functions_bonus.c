#include "push_swap_bonus.h"

void	free_buf(char *instruct, char *in)
{
	if (instruct)
		free(instruct);
	free(in);
	get_next_line(0, 1);
}

void	result(t_stack **a, t_stack **b, char **in)
{
	int	i;

	i = 0;
	if (sorted(*a) && ft_stksize(*b) == 0)
		ft_putstr_fd("OK", 1);
	else
	{
		if (ft_stksize(*b) != 0)
			ft_stkclear(b);
		ft_putstr_fd("KO", 1);
	}
	while (in[i])
	{
		free(in[i]);
		i++;
	}

	free(in);
	free(b);
	ft_stkclear(a);
	exit(0);
}

void	push(t_stack **a, t_stack **b, char in)
{
	if (in == 'a')
		pa(a, b);
	else
		pb(a, b);
}

void	rev_or_rot(t_stack **a, t_stack **b, char *in)
{
	if (in[1] == 'a')
		(*a) = rotate(*a);
	else if (in[1] == 'b')
		(*b) = rotate(*b);
	else
	{
		if (ft_strlen(in) == 2)
			both(a, b, 2);
		else
		{
			if (in[2] == 'a')
				(*a) = reverse_rotate(*a);
			else if (in[2] == 'b')
				(*b) = reverse_rotate(*b);
			else
				both(a, b, 3);
		}
	}
}
