#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
typedef struct s_stack
{
    int num;
    int index;
    struct s_stack *next;
}t_stack;

/******utils**** */
int	ft_stksize(t_stack *a);
t_stack	*ft_stklast(t_stack *stack);
t_stack	*ft_stknew(int num);
t_stack *push_stack(int *num,int size);
int	*add(int ac, char **av,int *size);

/******handler**** */
void	ft_error(int *num);
int		countword(int *ac, char **av);
int		*space(int *num, char *av, int *size);
int		duplicated(int *num, int number, int index);
int	sorted(t_stack *a);


/*******operations****** */
void pb(t_stack **a,t_stack **b);
void pa(t_stack **a,t_stack **b);
t_stack	*sa(t_stack *a);
t_stack	*ra(t_stack *a);
t_stack	*rra(t_stack *a);
/*******sorting**** */
void sort_3(t_stack **a);
void sort_5(t_stack **a,int size);
void bubble_sort(t_stack *a,int *num,int size);
t_stack *indexing(t_stack *a);
#endif