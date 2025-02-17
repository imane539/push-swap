#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	int				position;
	struct s_stack	*next;
}					t_stack;

/******stack_operations**** */
int					ft_stksize(t_stack *a);
t_stack				*ft_stklast(t_stack *stack);
t_stack				*ft_stknew(int num);
t_stack				*push_stack(int *num, int size);
int					*add(int ac, char **av, int *size);

/******handler**** */
void				ft_error(int *num, char **av);
int					countword(int *ac, char **av);
int					*space(int *num, char *av, int *size);
int					duplicated(int *num, int number, int index);
int					sorted(t_stack *a);

/*******operations****** */
void				pb(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
t_stack				*swap(t_stack *a, int check);
t_stack				*rotate(t_stack *a, int check);
t_stack				*reverse_rotate(t_stack *a, int check);
/************utils****** */
t_stack				*get_max(t_stack *b);
void				push_to_b(t_stack **a, t_stack **b);
t_stack				*position(t_stack *a);
void				bubble_sort(t_stack *a, int *num, int size);
t_stack				*indexing(t_stack *a);

/*******sorting**** */
void				sort_large(t_stack **a, int size);
void				sort_3(t_stack **a);
void				sort_5(t_stack **a, int size);
int					is_empty(char *str);
/********chunk *******/
void				push_two(t_stack **a, t_stack **b);
t_stack				**fill_b(t_stack **a, int range);
t_stack				**fill_a(t_stack **a, t_stack **b);
void				ft_sktclear(t_stack **a);
t_stack				*get_min(t_stack *a);
#endif