/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 13:32:51 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/10 17:51:55 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	if (size == 0 || !(ptr = malloc(size)))
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}
