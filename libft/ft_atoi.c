/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:18:11 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/02/16 10:56:49 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
static void handler(long long *num, char str, int sign,int *error)
{
		*num = (*num * 10) + str - 48;
		if(((*num) * sign > 2147483647) || ((*num) * sign < -2147483648) || *num == 9223372036854775807)
		{
			*error = 1;
		}
}
int	ft_atoi(const char *str, int *error)
{
	int		(i),(sign),(count);
	long long	num;

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
		if(!str[i])
		*error = 1;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
 		handler(&num,str[i++],sign,error);
	if ((str[i] && (str[i] < 48 || str[i] > 57)))
		*error = 1;
	return (num * sign);
}
