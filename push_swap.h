#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
typedef struct s_stack
{
    int num;
    int index;
    struct s_stack *next;
}t_stack;
t_stack *push_stack(int *num,int size);
int		duplicated(int *num, int number, int index);
int	*add(int ac, char **av,int *size);
void	ft_error(int *num);
int	sorted(t_stack *a);
int		countword(int *ac, char **av);
int		*space(int *num, char *av, int *size);
t_stack	*sa(t_stack *a);
void sort_3(t_stack **a,int size);
#endif