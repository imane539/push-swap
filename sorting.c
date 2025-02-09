#include "push_swap.h"
void sort_3(t_stack **a,int size)
{
    if(size == 2)
    {
        *a = sa(*a);
        ft_putstr_fd("sa\n",1);
        exit(0);
    }
    else
    {

    }
}
void indexing(t_stack **a)
{
    t_stack *min;
    t_stack **tmp;
    int index;
    index = 0;
    tmp = a;
    min = (*tmp);
    (*tmp)=(*tmp)->next;
    while((*tmp)->next)
    {
        while((*tmp) && (*tmp)->num > min->num)
        {
             (*tmp)=(*tmp)->next;
            while((*tmp) && (*tmp)->num < min)
            {
                min = (*tmp);
             (*tmp)=(*tmp)->next;
            // (*tmp)->index=index;
            // index++;
            }
        }
   
    }
}
t_stack	*sa(t_stack *a)
{
	t_stack *tmp;
    tmp = a;
    a = a->next;
    tmp->next = a->next;
    a->next = tmp;
	return (a);
}