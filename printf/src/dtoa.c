/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:02:24 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 09:09:52 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	int_part_len(long double nbr)
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

static int	add_integral_part(char *result, double int_part, int len)
{
	int		i;
	int		j;
	double	dbl_tmp;
	double	res;
	int		int_tmp;

	i = 0;
	if (ft_isnegative(int_part))
		result[i++] = '-';
	int_part = ft_fabs(int_part);
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

static int	add_fractional_part(char *result, long double frac_part,
int precision)
{
	int			i;
	long double	long_fraction;

	if (precision == 0)
		return (0);
	long_fraction = ft_fabsl(frac_part);
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

char	*ft_dtoa(double nbr, size_t precision)
{
	char		*result;
	int			len;
	double		int_part;
	long double	frac_part;

	if (ft_isnan(nbr))
		return (ft_strdup("nan"));
	else if (ft_isposinf(nbr) || ft_isneginf(nbr))
		return (ft_isposinf(nbr) ? ft_strdup("inf") : ft_strdup("-inf"));
	frac_part = round_double(ft_modf(nbr, &int_part), precision);
	if (frac_part >= 1.0 || frac_part <= -1)
	{
		int_part += (int)frac_part;
		frac_part -= (int)frac_part;
	}
	else if (rounds_half_to_even(nbr, precision) &&
	(uintmax_t)(ft_fabs(int_part) + 1) % 2 == 0)
		int_part += (ft_isnegative(nbr)) ? -1 : 1;
	len = ft_isnegative(nbr) + int_part_len(int_part) +
	((precision != 0) ? 1 : 0) + precision;
	if (!(result = (char *)ft_memalloc(len + 1)))
		return (NULL);
	len = add_integral_part(result, int_part, int_part_len(int_part));
	add_fractional_part(&result[len], frac_part, precision);
	return (result);
}
