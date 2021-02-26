/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:02:24 by skoskine          #+#    #+#             */
/*   Updated: 2021/02/25 19:44:23 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

static int		get_int_part_len(long double nbr)
{
	int	len;

	len = 1;
	while ((nbr > 0 && nbr / 10 >= 1.0) || (nbr < 0 && nbr / 10 <= -1.0))
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

static int		add_integral_part(char *result, double int_part, int len)
{
	int			i;
	int			j;
	double		dbl_tmp;
	double		res;
	int			int_tmp;

	i = 0;
	int_part = ft_isnegative(int_part) ? -int_part : int_part;
	while (len > 0)
	{
		dbl_tmp = int_part;
		j = 0;
		while (++j < len)
			dbl_tmp /= 10;
		int_tmp = (int)dbl_tmp;
		result[i++] = int_tmp + '0';
		len--;
		res = ft_dpow(10.0, len);
		res *= (double)int_tmp;
		int_part -= res;
	}
	return (i);
}

static int		add_fractional_part(char *result, long double frac_part,
int precision)
{
	int	i;
	long double long_fraction;

	long_fraction = (frac_part < 0.0) ? -frac_part : frac_part;
	i = 0;
	result[i++] = '.';
	while (precision-- > 0)
	{
		long_fraction *= 10;
		result[i++] = (int)long_fraction + '0';
		long_fraction -= (int)long_fraction;
	}
	return (i);
}

static long double	round_double(double nbr, size_t precision)
{
	size_t		i;
	long double	div;
	long double	long_nbr;

	i = 0;
	div = 1.0;
	long_nbr = nbr;
	while (i++ < precision)
		div *= 10;
	if (ft_isnegative(nbr))
		long_nbr = (long_nbr - 0.5 / div);
	else
		long_nbr = (long_nbr + 0.5 / div);
	return (long_nbr);
}

char			*ft_dtoa(double nbr, size_t precision)
{
	char	*result;
	int		len;
	double	int_part;
	double	frac_part;
//	long double long_nbr;

	if (ft_isnan(nbr))
		return (ft_strdup("nan"));
	else if (ft_isposinf(nbr))
		return (ft_strdup("inf"));
	else if (ft_isneginf(nbr))
		return (ft_strdup("-inf"));
	nbr = round_double(nbr, precision);
	len = ft_isnegative(nbr) + get_int_part_len(nbr) +
		((precision != 0) ? 1 : 0) + precision;
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	if (nbr < 0.0)
		result[len++] = '-';
	frac_part = modf(nbr, &int_part);
	len += add_integral_part(&result[len], int_part, get_int_part_len(nbr));
	if (precision != 0)
		len += add_fractional_part(&result[len], frac_part, precision);
	result[len] = '\0';
	return (result);
}
