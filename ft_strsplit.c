/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 17:16:18 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/10 17:50:20 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_count_strings(char const *s, char c)
{
	int		string_count;
	size_t	i;

	string_count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			string_count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (string_count);
}

static size_t	ft_next_word_length(char const *s, char c, size_t i)
{
	size_t len;

	len = 0;
	while (s[i + len] != c && s[i + len] != '\0')
		len++;
	return (len);
}

static char		**ft_free_array(char **arr, int size)
{
	while (size > 0)
	{
		free(arr[size - 1]);
		size--;
	}
	free(arr);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	len;
	int		j;
	int		word_count;

	if (s == 0)
		return (NULL);
	word_count = ft_count_strings(s, c);
	if (!(arr = (char**)malloc(sizeof(*arr) * (word_count + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < word_count)
	{
		while (s[i] == c)
			i++;
		len = ft_next_word_length(s, c, i);
		if (!(arr[j] = ft_strsub(s, i, len)))
			return (ft_free_array(arr, j - 1));
		i += len;
		j++;
	}
	arr[j] = 0;
	return (arr);
}
