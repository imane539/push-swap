#include "push_swap.h"
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
}
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
	{
		ft_sktclear(&a);
		return (0);
	}
	if(size == 2)
    {
        a = swap(a,1);
		ft_sktclear(&a);
        return(0);
    }
	a = indexing(a);
	if(size < 6)
	{
		sort_5(&a ,size);
		ft_sktclear(&a);
		return (0);
	}
	
	sort_large(&a,size);
}
