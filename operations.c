#include "push_swap.h"
void pb(t_stack **a,t_stack **b)
{
    if(!b)
        b = malloc(sizeof(t_stack *));
    
    t_stack **tmp;
    tmp = a;
    a = b;
    b = b->next;
    a->next = tmp;
}
void pa(t_stack **a,t_stack **b)
{
    t_stack **tmp;
    tmp = a;
    a = b;
    b = b->next;
    a->next = tmp;
}
t_stack	*sa(t_stack *a)
{
	t_stack *tmp;
    tmp = a;
    a = a->next;
    tmp->next = a->next;
    a->next = tmp;
    ft_putstr_fd("sa\n",1);
	return (a);
}
t_stack	*ra(t_stack *a)
{
	t_stack *tmp;
    t_stack *last;
    last = ft_stklast(a);
    tmp = a;
    a = a->next;
    last->next = tmp;
    tmp->next=NULL;
    ft_putstr_fd("ra\n",1);

	return (a);
}
t_stack	*rra(t_stack *a)
{
	t_stack *tmp;
	t_stack *last;

    tmp = a;
    last = a;
    a = ft_stklast(a);
    while(last->next->next)
        last = last->next;
    a->next = tmp;
    last->next = NULL;
    ft_putstr_fd("rra\n",1);
	return (a);
}