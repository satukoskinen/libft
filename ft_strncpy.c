/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:54:27 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/10 17:50:39 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t src_len;

	src_len = ft_strlen(src);
	if (src_len >= len)
		return (ft_memcpy(dst, src, len));
	ft_memcpy(dst, src, src_len);
	ft_memset(&dst[src_len], 0, len - src_len);
	return (dst);
}
