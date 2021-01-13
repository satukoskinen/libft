/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 18:10:54 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/10 17:52:15 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_number_length(int n)
{
	int length;

	length = 1;
	if (n < 0)
		length++;
	while (n / 10 != 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		length;
	int		div;

	i = 0;
	length = ft_number_length(n);
	if (!(str = malloc(sizeof(*str) * (length + 1))))
		return (NULL);
	if (n < 0)
	{
		str[i] = '-';
		i++;
		length--;
	}
	while (length > 0)
	{
		div = ft_power(10, length - 1);
		str[i] = ft_abs(n / div) + 48;
		n %= div;
		i++;
		length--;
	}
	str[i] = '\0';
	return (str);
}
