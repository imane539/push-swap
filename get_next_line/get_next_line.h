/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:22:22 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/02/17 21:22:24 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif /* BUFFER_SIZE */

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd, int error);
char	*ft_line(char **line, char *buffer);
int		check_line(char *buff);
char	*ft_read(int fd, char **line, char *buffer);
char	*ft_stop(char **buf);
#endif /* GET_NEXT_LINE_H */
