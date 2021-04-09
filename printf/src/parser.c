/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 21:28:28 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 09:27:39 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

static int	parse_conversion(t_data *specs, va_list *ap, char **result)
{
	int	ret;

	if (specs->conversion == '%')
		ret = parse_char(specs, '%', result);
	else if (specs->conversion == 'c')
		ret = parse_char(specs, va_arg(*ap, int), result);
	else if (specs->conversion == 's')
		ret = parse_string(specs, va_arg(*ap, char *), result);
	else if (specs->conversion == 'p')
		ret = parse_pointer(specs, va_arg(*ap, void *), result);
	else if (ft_strchr("di", specs->conversion))
		ret = parse_signed_ints(specs, ap, result);
	else if (ft_strchr("ouxX", specs->conversion))
		ret = parse_unsigned_ints(specs, ap, result);
	else if (ft_strchr("fF", specs->conversion))
		ret = parse_doubles(specs, ap, result);
	else
		ret = -1;
	return (ret);
}

static int	append_to_result(char **result, int ret, int len, char *str)
{
	static int	arr_size = 100;

	if (len == -1)
		return (-1);
	if (*result == NULL)
	{
		*result = ft_memalloc(arr_size + 1);
		if (*result == NULL)
			return (-1);
	}
	if (ret + len > arr_size)
	{
		*result = ft_realloc(*result, arr_size, arr_size * 2 + len + 1);
		if (*result == NULL)
			return (-1);
		arr_size = arr_size * 2 + len;
	}
	ft_memcpy(&(*result)[ret], str, len);
	return (len);
}

int	get_conversion(const char *format, va_list *ap, char **str, int *i)
{
	int		ret;
	t_data	conversion_specs;

	ft_memset((void *)&conversion_specs, 0, sizeof(t_data));
	*i += get_conversion_specs(&conversion_specs, &format[*i + 1]);
	ret = parse_conversion(&conversion_specs, ap, str);
	return (ret);
}

int	parse(const char *format, va_list *ap, char **result)
{
	int		i;
	int		final_ret;
	int		ret;
	char	*conversion;

	i = 0;
	final_ret = 0;
	ret = 0;
	conversion = NULL;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret = get_conversion(format, ap, &conversion, &i);
			ret = append_to_result(result, final_ret, ret, conversion);
			ft_strdel(&conversion);
		}
		else
			ret = append_to_result(result, final_ret, 1, (char *)&format[i]);
		if (ret == -1)
			break ;
		final_ret += ret;
		i++;
	}
	if (ret == -1)
		return (-1);
	if (i == 0)
		*result = ft_strdup("");
	return (final_ret);
}
