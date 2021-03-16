/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dpow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 09:15:48 by skoskine          #+#    #+#             */
/*   Updated: 2021/02/15 22:19:17 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_dpow(double base, int power)
{
	double result;

	result = 1.0;
	while (power > 0)
	{
		result *= base;
		power--;
	}
	return (result);
}
