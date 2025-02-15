#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_stack
{
	int				num;
	int				index;
	int				position;
	struct s_stack	*next;
}					t_stack;
/*********functions***** */
void push(t_stack **a,t_stack **b,char in);
void rev_or_rot(t_stack **a,t_stack **b,char *in);
void result(t_stack **a,t_stack **b);
/******stack_operations**** */
int					ft_stksize(t_stack *a);
t_stack				*ft_stklast(t_stack *stack);
t_stack				*ft_stknew(int num);
void	ft_sktclear(t_stack **a);
t_stack				*push_stack(int *num, int size);
int					*add(int ac, char **av, int *size);
/******handler**** */
void				ft_error(int *num);
int					countword(int *ac, char **av);
int					*space(int *num, char *av, int *size);
int					duplicated(int *num, int number, int index);
int					sorted(t_stack *a);

/*******operations****** */
void				pb(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
t_stack				*swap(t_stack *a);
t_stack				*rotate(t_stack *a);
t_stack				*reverse_rotate(t_stack *a);

/************utils****** */
char **read_instructions(t_stack **a);
void check_instructions(char *in,t_stack **a);
void execute_instructions(t_stack **a,char **instructions);
void	both(t_stack **a, t_stack **b,int check);
void	errors(char *str,t_stack **a);

#endif