#include "push_swap.h"

int	*add(int ac, char **av,int *size)
{
	int	*num;

	int (j), (sum), (error);
	error = 0;
	// i = 0;
	j = 0;
	sum = countword(&ac, av) + (ac - 1);
	num = malloc(sum * sizeof(int));
	if (!num)
		exit(1);
	// i = 0;
	while ((*size) < sum)
	{
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

int	*sa(int *num)
{
	int tmp;

	tmp = num[0];
	num[0] = num[1];
	num[1] = tmp;
	return (num);
}
