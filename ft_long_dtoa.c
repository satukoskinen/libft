/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_dtoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:30:14 by skoskine          #+#    #+#             */
/*   Updated: 2021/01/27 22:12:29 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

long double	ft_modfl(long double value, long double *iptr)
{
	int			int_tmp;
	long double	d_tmp;

	int_tmp = (int)value;
	d_tmp = (double)int_tmp;
	*iptr = d_tmp;
	return (value - d_tmp);
}

static int	add_integral_part(char *result, long double nbr, int len)
{
	int	i;

	i = 0;
	
	return (i);
}

static int	add_decimal_part(char *result, long double nbr, int precision)
{
	int	i;

	i = 0;
	
	return (i);
}

static int	get_integral_part_len(long double nbr)
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

char		*ft_long_dtoa(long double nbr, size_t precision)
{
	char	*result;
	int		result_len;
	int		integral_part_len;
	int		i;

	integral_part_len = get_integral_part_len(nbr);
	result_len = integral_part_len + precision +
	((precision != 0) ? 1 : 0) + ((nbr < 0) ? 1 : 0);
	if (!(result = (char*)malloc(sizeof(char) * (result_len + 1))))
		return (NULL);
	i = 0;
	if (nbr < 0)
		result[i++] = '-';
	i += add_integral_part(&result[i], nbr, integral_part_len);
	if (precision != 0)
	{
		result[i++] = '.';
		i += add_decimal_part(&result[i], nbr, precision);
	}
	result[i] = '\0';
	return (result);
}

int main(void)
{
	double var = 454423.3432423;
	double var2;
	
	var = ft_modf(var, &var2);
	printf("%.10f %.10f\n", var, var2);
	return (0);
}