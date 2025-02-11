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
	// 	int i = 0;

	// 	while(i < size)
	// {
	// 	printf("%d\n",num[i++]);
	// }
	if (sorted(a) == 1 || size == 1)
	{
		free(num);
		return (0);
	}
	num = bubble_sort(num,size);
	if(size < 6)
	{
		sort_5(&a , size,num);
	}
	// a = sort(a);
	// 	while(a)
	// {
	// 	printf("%d\n",a->num);
	// 	a = a->next;
	// }
}
