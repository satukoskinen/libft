/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 08:42:46 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/08 18:57:34 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_modf(double value, double *iptr)
{
	unsigned long long	double_as_int;
	unsigned char		sign;
	short				exponent;
	unsigned long long	significand;

	*iptr = value;
	if (value == 0.0 || value == -0.0 || ft_isnan(value))
		return (value);
	else if (ft_isposinf(value) || ft_isneginf(value))
		return (ft_isposinf(value) ? 0.0 : -0.0);
	ft_memcpy(&double_as_int, &value, sizeof(value));
	sign = (unsigned char)(double_as_int >> 63);
	exponent = (unsigned short)(double_as_int >> 52 & 0x7FF) - 1023;
	significand = (double_as_int & 0x0000FFFFFFFFFFFFFULL) | (1ULL << 52);
	if (exponent < 0)
		*iptr = (sign == 0 ? 0.0 : -0.0);
	else if (exponent == 0)
		*iptr = (sign == 0 ? 1.0 : -1.0);
	else if (exponent > 52)
		*iptr = value;
	else
		*iptr = (sign == 0 ? 1.0 : -1.0) * (significand >> (52 - exponent));
	return (value - *iptr);
}
