/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 10:35:52 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 10:00:14 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
double	ft_fabs(double nbr)
{
=======
long double	ft_fabsl(long double nbr)
{
	if (nbr < 0.0 || nbr == -0.0)
		return (-nbr);
	else
		return (nbr);
}

double	ft_fabs(double nbr)
{
>>>>>>> e64654f625eaaf9f76d156940a1f4cb404ab8e54
	if (ft_isnegative(nbr))
		return (-nbr);
	else
		return (nbr);
}
