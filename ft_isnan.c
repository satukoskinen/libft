/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:35:55 by skoskine          #+#    #+#             */
/*   Updated: 2021/02/15 22:36:09 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isnan(double nbr)
{
	return (nbr != nbr ? 1 : 0);
}
