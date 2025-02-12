#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	int *num;
   int size;

    size = 0;
	if (ac == 1)
		return (0);
	num = add(ac, av,&size);
	a = push_stack(num,size);
	free(num);
	if (sorted(a) == 1 || size == 1)
		return (0);
	if(size == 2)
    {
        a = sa(a);
        exit(0);
    }
	a = indexing(a);
	if(size < 6)
	{
		sort_5(&a ,size);
		return (0);
	}
	sort_large(&a,size);
}
