#include "push_swap.h"
void sort_large(t_stack **a,int size)
{
    int range;
    int i;
    t_stack **b;

    i = 0;
    if(size > 400)
        range = 36;
    else
    range = 16;
    (*a) = position(*a);
    b = malloc(sizeof(t_stack *));
    while(ft_stksize(*a) != 0)
    {
        if((*a)->index < i)
        {
            push_to_b(a,b);
            (*b) = ra(*b);
        }
        else if((*a)->index <= i+range)
            push_to_b(a,b);
        else
            push_to_b(a,b);
        i++;
        
    }
       while(*b)
	{
		printf("b:%d\n",(*b)->num);
		(*b) = (*b)->next;
	}
    
    // while(*a)
	// {
	// 	printf("a:%d\n",(*a)->position);
	// 	(*a) = (*a)->next;
	// }
}
void sort_3(t_stack **a)
{
    if((*a)->index == 0)
    {
        (*a) = sa(*a);
        (*a) = ra(*a);
    }
   else if((*a)->index == 1)
    {
        if((*a)->next->index == 0)
            (*a) = sa(*a);
        else
            (*a) = rra(*a);
    }
    else
    {
        if((*a)->next->index == 0)
            (*a) = ra(*a);
        else
        {
            (*a) = sa(*a);
            (*a) = rra(*a); 
        }
    }
   
}
void sort_5(t_stack **a,int size)
{
    t_stack **b;
    b = NULL;

    (*a) = indexing(*a);
    if(size == 3)
    {
        sort_3(a);
        exit(0);
    }
    else
    {
        b = malloc(sizeof(t_stack *));
        while(ft_stksize(*a) != 3)
        {
            if((*a)->index == 0)
            {
                pb(a,b);
                (*a) = indexing(*a);
            }
            else if((*a)->next->index == 0)
                (*a) = sa(*a);
            else
                (*a) = ra(*a);
        }
        if(!sorted(*a))
            sort_3(a);
        while(*b)
                pa(a,b);
    }
}


