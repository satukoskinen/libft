/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isposinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:36:22 by skoskine          #+#    #+#             */
/*   Updated: 2021/02/18 18:45:32 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isposinf(double nbr)
{
	return (nbr == 1.0 / 0 ? 1 : 0);
}