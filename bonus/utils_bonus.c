#include "push_swap_bonus.h"

void	both(t_stack **a, t_stack **b, int check)
{
	if(!ft_stksize(*a) || !ft_stksize(*a))
	return ;
	if (check == 1)
	{
		(*a) = swap(*a);
		(*b) = swap(*b);
	}
	else if (check == 2)
	{
		(*a) = rotate(*a);
		(*b) = rotate(*b);
	}
	else
	{
		(*a) = reverse_rotate(*a);
		(*b) = reverse_rotate(*b);
	}
}

void	errors(char *str, t_stack **a)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	ft_stkclear(a);
	exit(1);
}

void	check_instructions(char *in, t_stack **a, char *instruct)
{
	char	*instructions[11];
	int		i;

	instructions[0] = "sa";
	instructions[1] = "sb";
	instructions[2] = "ss";
	instructions[3] = "pa";
	instructions[4] = "pb";
	instructions[5] = "ra";
	instructions[6] = "rb";
	instructions[7] = "rr";
	instructions[8] = "rra";
	instructions[9] = "rrb";
	instructions[10] = "rrr";
	i = 0;
	while (i < 11)
	{
		if (ft_strncmp(in, instructions[i], ft_strlen(instructions[i])) == 0
			&& in[ft_strlen(instructions[i])] == '\n')
			return ;
		i++;
	}
	free_buf(instruct, in);
	errors("Error", a);
}

char	**read_instructions(t_stack **a)
{
	char	*line;
	char	*tmp;
	char	*instructions;
	char	**ins;

	instructions = NULL;
	line = get_next_line(0, 0);
	if (!line)
		errors("KO", a);
	while (line)
	{
		check_instructions(line, a, instructions);
		if (!instructions)
			instructions = ft_strdup(line);
		free(line);
		line = get_next_line(0, 0);
		tmp = ft_strjoin(instructions, line);
		free(instructions);
		instructions = ft_strdup(tmp);
		free(tmp);
	}
	ins = ft_split(instructions, '\n');
	free(instructions);
	return (ins);
}

void	execute_instructions(t_stack **a, char **instructions)
{
	int		i;
	t_stack	**b;

	b = malloc(sizeof(t_stack *));
	(*b) = NULL;
	i = 0;
	while (instructions[i])
	{
		if (instructions[i][0] == 'p')
			push(a, b, instructions[i][1]);
		else if (instructions[i][0] == 's')
		{
			if (instructions[i][1] == 'a')
				(*a) = swap(*a);
			else if (instructions[i][1] == 'b')
				(*b) = swap(*b);
			else
				both(a, b, 1);
		}
		else
			rev_or_rot(a, b, instructions[i]);
		i++;
	}
	result(a, b, instructions);
}
