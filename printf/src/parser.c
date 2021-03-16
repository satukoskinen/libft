/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 21:28:28 by skoskine          #+#    #+#             */
/*   Updated: 2021/02/19 16:44:25 by skoskine         ###   ########.fr       */
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
		ret = parse_string(specs, va_arg(*ap, char*), result);
	else if (specs->conversion == 'p')
		ret = parse_pointer(specs, va_arg(*ap, void*), result);
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
		if (!(*result = ft_memalloc(arr_size + 1)))
			return (-1);
	}
	if (ret + len > arr_size)
	{
		if (!(*result = ft_realloc(*result, arr_size, arr_size * 2 + len + 1)))
			return (-1);
		arr_size = arr_size * 2 + len;
	}
	ft_memcpy(&(*result)[ret], str, len);
	return (len);
}

int			get_conversion(const char *format, va_list *ap, char **str, int *i)
{
	int		ret;
	t_data	*conversion_specs;

	if (!(conversion_specs = (t_data*)malloc(sizeof(t_data))))
		return (-1);
	ft_memset((void*)conversion_specs, 0, sizeof(t_data));
	*i += get_conversion_specs(conversion_specs, &format[*i + 1]);
	ret = parse_conversion(conversion_specs, ap, str);
	free(conversion_specs);
	return (ret);
}

int			parse(const char *format, va_list *ap, char **result)
{
	int		i;
	int		final_ret;
	int		ret;
	char	*conversion;

	i = 0;
	final_ret = 0;
	ret = 0;
	while (format[i] && final_ret != -1)
	{
		if (format[i] == '%')
		{
			ret = get_conversion(format, ap, &conversion, &i);
			ret = append_to_result(result, final_ret, ret, conversion);
			if (ret != -1)
				free(conversion);
		}
		else
			ret = append_to_result(result, final_ret, 1, (char*)&format[i]);
		i++;
		final_ret = (ret == -1) ? -1 : final_ret + ret;
	}
	if (i == 0)
		*result = ft_strdup("");
	return (final_ret);
}
