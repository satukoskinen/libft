/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:35:54 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/24 22:10:05 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include <stdlib.h>

t_array	*arr_new(size_t capacity, size_t elem_size)
{
	t_array	*arr;

	arr = (t_array *)malloc(sizeof(t_array));
	if (arr == NULL)
		return (NULL);
	arr->capacity = capacity;
	arr->data = (void **)malloc(elem_size * capacity);
	if (arr->data == NULL)
		return (NULL);
	arr->size = 0;
	arr->elem_size = 0;
}

static t_array	*arr_resize(t_array *arr)
{
	;
}

t_array	*arr_add(t_array *arr, void *elem)
{
	;
}

t_array	*arr_insert(t_array *arr, void *elem, size_t index)
{
	;
}

void	arr_delone(t_array *arr, size_t index)
{
	;
}

void	arr_del(t_array *arr)
{
	;
}
