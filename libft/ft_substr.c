/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:21:28 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/02/17 21:21:30 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;
	unsigned int	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	if (start > size)
		return (ft_strdup(""));
	if (len > size - start)
		len = size - start;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i++] = s[start++];
	}
	p[i] = '\0';
	return (p);
}
