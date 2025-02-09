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
	// int i = 0;

	// 	while(i < size)
	// {
	// 	printf("%d\n",num[i++]);
	// }
	a = push_stack(num,size);

	if (sorted(a) == 1 || size == 1)
	{
		free(num);
		return (0);
	}
	if(size == 3 || size == 2)
	{
		sort_3(&a , size);
	}
	// a = sort(a);
		while(a)
	{
		printf("%d\n",a->num);
		a = a->next;
	}
}
