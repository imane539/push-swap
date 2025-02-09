/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:44:50 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/11 16:20:32 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	size;
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = malloc(size);
	if (!p)
		return (NULL);
	while (i < size - 1)
	{
		while (s1[i])
		{
			p[i] = s1[i];
			i++;
		}
		while (s2[j])
			p[i++] = s2[j++];
	}
	p[i] = '\0';
	return (p);
}
