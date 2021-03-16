/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:26:23 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/10 17:19:27 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	if (!(s2 = (char*)malloc(sizeof(char) * (s1_len + 1))))
		return (NULL);
	return (ft_memcpy(s2, s1, s1_len + 1));
}
