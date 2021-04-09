/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:24:38 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/24 21:29:48 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_asprintf(char **ret, const char *format, ...)
{
	va_list	ap;
	int		ret_value;

	va_start(ap, format);
	*ret = NULL;
	ret_value = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (ret_value);
}
