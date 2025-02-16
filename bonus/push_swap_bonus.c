#include "push_swap_bonus.h"

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
