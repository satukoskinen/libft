/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnegative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 08:40:49 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/24 19:04:01 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isnegative(double nbr)
{
	unsigned long long	*double_as_int;
	unsigned char		sign;

	double_as_int = (unsigned long long *)&nbr;
	sign = (unsigned char)(*double_as_int >> 63);
	if (sign == 0)
		return (0);
	else
		return (1);
}
