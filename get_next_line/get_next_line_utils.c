/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:22:21 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/02/15 13:22:38 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

int	check_line(char *buff)
{
	int	i;

	i = 0;
	if (!buff)
		return (0);
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
