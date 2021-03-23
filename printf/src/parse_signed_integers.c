/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_signed_integers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:39:54 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/23 14:16:00 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static intmax_t	get_signed_arg(t_data *specs, va_list *ap)
{
	intmax_t	value;

	if (ft_strcmp(specs->length_modifier, "hh") == 0)
		value = (signed char)va_arg(*ap, int);
	else if (ft_strcmp(specs->length_modifier, "h") == 0)
		value = (short)va_arg(*ap, int);
	else if (ft_strcmp(specs->length_modifier, "ll") == 0)
		value = va_arg(*ap, long long);
	else if (ft_strcmp(specs->length_modifier, "l") == 0)
		value = va_arg(*ap, long);
	else
		value = va_arg(*ap, int);
	return (value);
}

int				parse_signed_ints(t_data *specs, va_list *ap, char **result)
{
	intmax_t	value;
	char		*number;
	size_t		len;

	value = get_signed_arg(specs, ap);
	if (!(number = ft_intmax_itoa_base(value, 10)))
		return (-1);
	specs->is_zero = (value == 0) ? 1 : 0;
	specs->is_negative = (value < 0) ? 1 : 0;
	len = (specs->is_zero && specs->zero_precision) ? 0 : ft_strlen(number);
	if (specs->has_precision)
		specs->zero_padding = 0;
	specs->precision = (specs->precision > len - specs->is_negative) ?
		(specs->precision - len + specs->is_negative) : 0;
	len += specs->precision;
	if (value >= 0 && (specs->plus_signed || specs->blank_signed))
		len += 1;
	specs->min_field_width = (specs->min_field_width > len) ?
		(specs->min_field_width - len) : 0;
	len += specs->min_field_width;
	*result = parse_int_result(specs, number, len);
	free(number);
	return ((*result != NULL) ? (int)len : -1);
}
