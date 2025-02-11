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
void sort_5(t_stack **a,int size,int *num)
{
    if(size == 2)
    {
        *a = sa(*a);
        exit(0);
    }
    (*a) = indexing(*a,size,num);
    if(size == 3)
    {
        sort_3(a);
        exit(0);
    }
    // while(*a)
	// {
	// 	printf("%d\n",(*a)->num);
	// 	(*a) = (*a)->next;
	// }
   
}
t_stack *indexing(t_stack *a,int size,int *num)
{
    int i;
    t_stack *tmp;
    tmp = a;
    i = 0;
 
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
int *bubble_sort(int *num,int size)
{
    int max;
    int i;
    int j;
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
    return num;
}
