/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:44:42 by skoskine          #+#    #+#             */
/*   Updated: 2021/02/18 18:45:17 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	char	*result;
	char	*digits;
	char	temp[32 + 1];
	int		i;
	int		sign;

	digits = "0123456789ABCDEF";
	i = 32;
	sign = (value < 0) ? -1 : 1;
	temp[i--] = '\0';
	if (value != 0 && base >= 2 && base <= 16)
	{
		while (value != 0)
		{
			temp[i--] = digits[ft_abs(value % base)];
			value = value / base;
		}
		if (sign == -1 && base == 10)
			temp[i--] = '-';
	}
	else
		temp[i--] = '0';
	if (base < 2 || base > 16 || !(result = (char*)malloc(32 - i + 1)))
		return (NULL);
	return (ft_strcpy(result, &temp[i + 1]));
}
