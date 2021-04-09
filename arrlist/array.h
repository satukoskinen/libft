/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:35:03 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/24 22:08:50 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include "string.h"

typedef struct s_array
{
	void		**data;
	size_t		elem_size;
	size_t		capacity;
	size_t		size;
}				t_array;

#endif