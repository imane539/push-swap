#include "push_swap_bonus.h"
void result(t_stack **a,t_stack **b)
{
    if(sorted(*a) && ft_stksize(*b) == 0)
		ft_putstr_fd("OK", 1);
    else
		ft_putstr_fd("KO", 1);

    ft_sktclear(a);
    free(b);
    exit(0);
}
void push(t_stack **a,t_stack **b,char in)
{
    if(in == 'a')
        pa(a,b);
    else
        pb(a,b);
}
void rev_or_rot(t_stack **a,t_stack **b,char *in)
{
    if(in[1] == 'a')
        (*a) = rotate(*a);
    else  if(in[1] == 'b')
        (*b) = rotate(*b);
    else
    {
        if(ft_strlen(in) == 2)
            both(a,b,2);
        else
        {
             if(in[2] == 'a')
                (*a) = reverse_rotate(*a);
            else  if(in[2] == 'b')
                (*b) = reverse_rotate(*b);
            else
                both(a,b,3);
        }
    }
}
