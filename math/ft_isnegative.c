/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnegative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 08:40:49 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/31 08:43:34 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnegative(double nbr)
{
	unsigned long long	double_as_int;
	unsigned char		sign;

	ft_memcpy(&double_as_int, &nbr, sizeof(nbr));
	sign = (unsigned char)(double_as_int >> 63);
	return ((sign == 0) ? 0 : 1);
}
