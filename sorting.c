#include "push_swap.h"
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
    if(size == 2)
    {
        *a = sa(*a);
        exit(0);
    }
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
            pb(a,b);
        (*a) = indexing(*a);
        if(!sorted(*a))
            sort_3(a);
        while((*b) && ((*a)->num > (*b)->num))
        {
            pa(a,b);
        }
		

        if((*b) && ((*a)->num < (*b)->num))
        {
             ra(*a);
        printf("a:%d\n",(*a)->num);
		printf("b:%d\n",(*b)->num);
        }
           
    }
    // while(*a)
	// {
	// 	printf("a:%d\n",(*a)->num);
	// 	(*a) = (*a)->next;
	// }
    //    while(*b)
	// {
	// 	printf("b:%d\n",(*b)->num);
	// 	(*b) = (*b)->next;
	// }
   
}
t_stack *indexing(t_stack *a)
{
    int (i),(size);
    int *num;
    t_stack *tmp;
    size = ft_stksize(a);
    tmp = a;
    i = 0;
    num = malloc(sizeof(int) * size);
    bubble_sort(a,num,size);
        while(a)
        {
            i = 0;
            while(i < size)
            {
                if(a->num == num[i])
                    a->index = i;
                i++;
            }
            a = a->next;
        }
    return tmp;
}
void bubble_sort(t_stack *a,int *num,int size)
{
    int (i),(max),(j);
    
    j = 0;
    while(j < size)
    {
        num[j++] = a->num;
        a = a->next;
    }
    j = 0;
    while(j < size)
    {
        i = 0;
        max = num[i++];
        while(i < size - j)
        {
            if(num[i] < max)
            {
                num[i - 1] = num[i];
                num[i] = max;
            }
            else 
            max = num[i];
            i++;
        } 
        j++;
    }
}
