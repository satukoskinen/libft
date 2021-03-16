/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 15:12:01 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/10 17:50:54 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*mapping;
	size_t	i;

	if (s == 0 || !(mapping = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		mapping[i] = f(s[i]);
		i++;
	}
	mapping[i] = '\0';
	return (mapping);
}
