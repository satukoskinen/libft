/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pointers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:08:42 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 09:01:37 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

int	parse_pointer(t_data *specs, void *ptr, char **result)
{
	uintmax_t	value;
	char		*number;
	size_t		result_len;

	value = (uintmax_t)ptr;
	if (!(number = ft_uintmax_itoa_base(value, 16, 0)))
		return (-1);
	result_len = ft_strlen(number) + 2;
	specs->conversion = 'x';
	specs->alt_form = 1;
	specs->has_precision = 0;
	specs->precision = 0;
	specs->min_field_width = (specs->min_field_width > result_len) ?
		(specs->min_field_width - result_len) : 0;
	result_len += specs->min_field_width;
	if (!(*result = parse_int_result(specs, number, result_len)))
		return (-1);
	free(number);
	return (result_len);
}
