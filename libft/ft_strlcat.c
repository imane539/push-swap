/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:20:43 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/02/17 21:20:46 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	destsize;
	size_t	k;

	k = 0;
	destsize = 0;
	j = 0;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i])
		i++;
	while (dest[destsize])
		destsize++;
	if (destsize >= size)
		return (i + size);
	k = destsize;
	while (k < size - 1 && src[j])
	{
		dest[k++] = src[j++];
	}
	dest[k] = '\0';
	return (i + destsize);
}
