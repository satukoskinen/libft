/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:02:24 by skoskine          #+#    #+#             */
/*   Updated: 2021/01/27 22:22:33 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

double		ft_modf(double value, double *iptr)
{
	int		int_tmp;
	double	d_tmp;

	int_tmp = (int)value;
	d_tmp = (double)int_tmp;
	*iptr = d_tmp;
	return (value - d_tmp);
}

static int	add_integral_part(char *result, double nbr, int len)
{
	int	i;

	i = 0;
	
	return (i);
}

static int	add_fractional_part(char *result, double nbr, int precision)
{
	int	i;

	i = 0;
	
	return (i);
}

static int	get_integral_part_len(double nbr)
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

char		*ft_dtoa(double nbr, size_t precision)
{
	char	*result;
	int		result_len;
	int		int_part_len;
	int		i;
	double	int_part;
	double	frac_part;

	int_part_len = get_integral_part_len(nbr);
	result_len = int_part_len + precision + ((precision != 0) ?
	1 : 0) + ((nbr < 0) ? 1 : 0);
	if (!(result = (char*)malloc(sizeof(char) * (result_len + 1))))
		return (NULL);
	i = 0;
	if (nbr < 0)
		result[i++] = '-';
	frac_part = ft_modf(nbr, &int_part);
	i += add_integral_part(&result[i], nbr, int_part_len);
	if (precision != 0)
	{
		result[i++] = '.';
		i += add_fractional_part(&result[i], nbr, precision);
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