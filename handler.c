#include "push_swap.h"

void	ft_error(int *num)
{
	ft_putstr_fd("Error\n", 2);
	free(num);
	exit(1);
}

int	countword(int *ac, char **av)
{
	int (i), (count), (j);
	int (index);
	index = 0;
	count = 0;
	i = 0;
	while (i < *ac - 1)
	{
		if (ft_strchr(av[i + 1], ' '))
		{
			index++;
			j = 0;
			while (av[i + 1][j])
			{
				while (av[i + 1][j] == ' ')
					j++;
				if (av[i + 1][j] != ' ' && av[i + 1][j])
					count++;
				while (av[i + 1][j] != ' ' && av[i + 1][j])
					j++;
			}
		}
		i++;
	}
	*ac -= index;
	return (count);
}

int	*space(int *num, char *av, int *size)
{
	int		j;
	int		error;
	char	**args;

	error = 0;
	j = 0;
	args = ft_split(av, ' ');
	while (args[j])
		j++;
	j = 0;
	while (args[j])
	{
		num[*size] = ft_atoi(args[j], &error);
		if (error == 1 || duplicated(num, num[*size], *size) == 1)
			ft_error(num);
		j++;
		(*size)++;
	}
	free(args);
	return (num);
}

int	duplicated(int *num, int number, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (num[i] == number)
			return (1);
		i++;
	}
	return (0);
}

int	sorted(int size, int *num)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (num[i] > num[i + 1])
			return (0);
		i++;
	}
	return (1);
}
