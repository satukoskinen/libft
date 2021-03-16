/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:26:30 by skoskine          #+#    #+#             */
/*   Updated: 2021/02/18 21:40:37 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int			ft_vasprintf(char **ret, const char *format, va_list ap)
{
	int		ret_value;
	va_list	ap_copy;

	va_copy(ap_copy, ap);
	*ret = NULL;
	ret_value = parse(format, &ap_copy, ret);
	va_end(ap_copy);
	return (ret_value);
}
