/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmax_itoa_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:54:43 by skoskine          #+#    #+#             */
/*   Updated: 2021/02/05 19:34:31 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <inttypes.h>
#include "libft.h"

char		*ft_uintmax_itoa_base(uintmax_t n, int base, int uppercase)
{
	char	*base_digits;
	char	*digit;
	char	*next_digit;
	char	*final_str;

	if (uppercase)
		base_digits = "0123456789ABCDEF";
	else
		base_digits = "0123456789abcdef";
	if (base < 2 || base > 16 || !(digit = ft_strnew(2)))
		return (NULL);
	if (n < (uintmax_t)base)
		return (ft_strncat(digit, &base_digits[n % base], 1));
	digit[0] = base_digits[n % base];
	if (!(next_digit = ft_uintmax_itoa_base(n / base, base, uppercase)))
	{
		free(digit);
		return (NULL);
	}
	final_str = ft_strjoin(next_digit, digit);
	free(digit);
	free(next_digit);
	return (final_str);
}
