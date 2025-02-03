#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int		duplicated(int *num, int number, int index);
int	*add(int ac, char **av,int *size);
void	ft_error(int *num);
int		sorted(int size, int *num);
int		countword(int *ac, char **av);
int		*space(int *num, char *av, int *size);
int		*sa(int *num);
int *merge(int *a,int size);
int **fill(int *a,int size);
int **allocate(int size);
#endif