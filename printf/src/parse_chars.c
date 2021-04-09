/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:40:23 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 09:01:18 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static char	*parse_str_result(t_data *specs, char *str, size_t str_len)
{
	size_t	result_len;
	size_t	i;
	size_t	j;
	char	*result;

	result_len = str_len + specs->min_field_width;
	if (!(result = (char *)malloc(sizeof(char) * (result_len + 1))))
		return (NULL);
	i = 0;
	if (specs->min_field_width > 0 && !specs->zero_padding &&
		!specs->neg_field_width)
		i += add_padding(specs->min_field_width, ' ', &result[i]);
	else if (specs->min_field_width > 0 && specs->zero_padding &&
		!specs->neg_field_width)
		i += add_padding(specs->min_field_width, '0', &result[i]);
	j = 0;
	while (j < str_len)
		result[i++] = str[j++];
	if (specs->min_field_width > 0 && specs->neg_field_width)
		i += add_padding(specs->min_field_width, ' ', &result[i]);
	result[i] = '\0';
	return (result);
}

int	parse_string(t_data *specs, char *str, char **result)
{
	size_t	i;

	if (str == NULL)
	{
		i = (specs->has_precision && specs->precision < 6) ?
		specs->precision : 6;
		specs->min_field_width = (specs->min_field_width > i) ?
			(specs->min_field_width - i) : 0;
		*result = parse_str_result(specs, "(null)", i);
	}
	else
	{
		i = 0;
		while ((!specs->has_precision || i < specs->precision)
		&& str[i] != '\0')
			i++;
		specs->min_field_width = (specs->min_field_width > i) ?
			(specs->min_field_width - i) : 0;
		*result = parse_str_result(specs, str, i);
	}
	if (*result == NULL)
		return (-1);
	else
		return (ft_strlen(*result));
}

int	parse_char(t_data *specs, char c, char **result)
{
	specs->min_field_width = (specs->min_field_width > 1) ?
		(specs->min_field_width - 1) : 0;
	if (!(*result = parse_str_result(specs, &c, 1)))
		return (-1);
	return (specs->min_field_width + 1);
}
