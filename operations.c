#include "push_swap.h"
void pb(t_stack **a,t_stack **b)
{
    if(!(*b))
    {
        (*b) = (*a);
        (*a) = (*a)->next;
        (*b)->next = NULL;
    }
    else
    {
        t_stack *tmp;
        tmp = (*b);
        (*b) = (*a);
        (*a) = (*a)->next;
        (*b)->next=tmp;
    }
    ft_putstr_fd("pb\n",1);

}
void pa(t_stack **a,t_stack **b)
{
    if(!(*a))
    {
        (*a) = (*b);
        (*b) = (*b)->next;
        (*a)->next = NULL;
    }
    else
    {
        t_stack *tmp;
        tmp = (*a);
        (*a) = (*b);
        (*b) = (*b)->next;
        (*a)->next=tmp;
    }
    ft_putstr_fd("pa\n",1);
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