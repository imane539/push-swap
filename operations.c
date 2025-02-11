#include "push_swap.h"
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