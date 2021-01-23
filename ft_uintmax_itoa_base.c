/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmax_itoa_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:54:43 by skoskine          #+#    #+#             */
/*   Updated: 2021/01/20 20:13:06 by skoskine         ###   ########.fr       */
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
	if (ft_abs(n) >= 0 && ft_abs(n) < base)
	{
		if (n < 0 && base == 10)
			digit[0] = '-';
		return (ft_strncat(digit, &base_digits[ft_abs(n % base)], 1));
	}
	digit[0] = base_digits[ft_abs(n % base)];
	if (!(next_digit = ft_itoa_base(n / base, base)))
	{
		free(digit);
		return (NULL);
	}
	final_str = ft_strjoin(next_digit, digit);
	free(digit);
	free(next_digit);
	return (final_str);
}
