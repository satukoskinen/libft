/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_unsigned_integers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 09:06:28 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 09:02:02 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static char	*get_value_string(t_data *specs, uintmax_t value)
{
	char	*result;

	if (specs->conversion == 'o')
		result = ft_uintmax_itoa_base(value, 8, 0);
	else if (specs->conversion == 'u')
		result = ft_uintmax_itoa_base(value, 10, 0);
	else if (specs->conversion == 'x')
		result = ft_uintmax_itoa_base(value, 16, 0);
	else
		result = ft_uintmax_itoa_base(value, 16, 1);
	return (result);
}

static uintmax_t	get_unsigned_arg(t_data *specs, va_list *ap)
{
	uintmax_t	value;

	if (ft_strcmp(specs->length_modifier, "hh") == 0)
		value = (unsigned char)va_arg(*ap, unsigned int);
	else if (ft_strcmp(specs->length_modifier, "h") == 0)
		value = (unsigned short)va_arg(*ap, unsigned int);
	else if (ft_strcmp(specs->length_modifier, "ll") == 0)
		value = va_arg(*ap, unsigned long long);
	else if (ft_strcmp(specs->length_modifier, "l") == 0)
		value = va_arg(*ap, unsigned long);
	else
		value = (uintmax_t)va_arg(*ap, unsigned int);
	return (value);
}

int	parse_unsigned_ints(t_data *specs, va_list *ap, char **result)
{
	uintmax_t	value;
	char		*number;
	size_t		len;

	value = get_unsigned_arg(specs, ap);
	if (!(number = get_value_string(specs, value)))
		return (-1);
	specs->is_zero = (value == 0) ? 1 : 0;
	if (specs->has_precision)
		specs->zero_padding = 0;
	len = (specs->is_zero && specs->zero_precision) ? 0 : ft_strlen(number);
	specs->precision = (specs->precision > len) ? (specs->precision - len) : 0;
	if (specs->alt_form && specs->conversion == 'o' && specs->precision == 0 &&
		(!specs->is_zero || specs->zero_precision))
		specs->precision++;
	len += specs->precision;
	if (specs->alt_form && ft_strchr("xX", specs->conversion) &&
		!specs->is_zero)
		len += 2;
	specs->min_field_width = (specs->min_field_width > len) ?
		(specs->min_field_width - len) : 0;
	len += specs->min_field_width;
	*result = parse_int_result(specs, number, len);
	free(number);
	return ((*result != NULL) ? (int)len : -1);
}
