/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:18:11 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/02/15 17:25:47 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

int	ft_atoi(const char *str, int *error)
{
	int		i;
	int		sign;
	long	num;
	int		count;

	count = 0;
	i = 0;
	sign = 1;
	num = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+') && count < 1)
	{
		count++;
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
		num = (num * 10) + str[i++] - 48;
	if ((str[i] && (str[i] < 48 || str[i] > 57)) || (num * sign > 2147483647)
		|| (num * sign < -2147483648))
		*error = 1;
	return (num * sign);
}
