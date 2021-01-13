/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:31:27 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/10 09:02:36 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_realloc(void *ptr, size_t ptr_size, size_t size)
{
	void	*new;

	if (size == 0 && ptr != NULL)
	{
		free(ptr);
		new = NULL;
	}
	else
		new = malloc(size);
	if (new != NULL && ptr != NULL)
	{
		ft_memcpy(new, ptr, (ptr_size > size ? size : ptr_size));
		free(ptr);
	}
	return (new);
}
