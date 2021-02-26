/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 08:42:46 by skoskine          #+#    #+#             */
/*   Updated: 2021/02/16 08:43:44 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <inttypes.h>
//#include "libft.h"

double		ft_modf(double value, double *iptr)
{
	unsigned long long	*double_as_int;
	unsigned char		sign;
	short				exponent;
	unsigned long long	significand;

	double_as_int = (unsigned long long*)&value;
//	printf("double as int %llx\n", *double_as_int);
	sign = (unsigned char)(*double_as_int >> 63);
	exponent = (unsigned short)(*double_as_int >> 52 & 0x7FF) - 1023;
	significand = (*double_as_int & 0x000FFFFFFFFFFFFFFULL) | (1ULL << 52);
//	printf("sign %hhx\nexponent %hd\nsignificand %llx\n", sign, exponent, significand);
//	printf("sign %s \nexponent %s\nsignificand %s\n", ft_uintmax_itoa_base((uintmax_t)sign, 2, 0), ft_uintmax_itoa_base((uintmax_t)exponent, 2, 0), ft_uintmax_itoa_base((uintmax_t)significand, 2, 0));
//	printf("significand %llu\nshifted%llu\n", significand, significand >> (52-exponent));
	if (exponent < 0)
		*iptr = 0;
	else if (exponent >= 52)
		*iptr = value;
	else if (exponent == 0)
		*iptr = (sign == 0 ? 1.0 : -1.0);
	else
		*iptr = (sign == 0 ? 1.0 : -1.0) * (significand >> (52 - exponent));
	if (sign == 0)
		return (value - *iptr);
	else
		return (value + *iptr);
}
