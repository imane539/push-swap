#include "push_swap.h"

int	main(int ac, char **av)
{
	int	*a;
	// int	*b;
    int size;
	// int	i;

    size = 0;
	if (ac == 1)
		return (0);
	a = add(ac, av,&size);
	if (sorted(size, a) == 1 || size == 1)
		return (0);
	if (size == 2)
	{
		a = sa(a);
		ft_putstr_fd("sa\n", 1);
		return (0);
	}
	a = merge(a,size);

	// i = 0;
	// while (a[i])
	// {
	// 	printf("%d\n", a[i++]);
	// }
	// (void)b;
}
