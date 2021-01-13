/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:31:05 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/10 17:52:01 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list *alst, t_list *new)
{
	t_list *p;

	p = alst;
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}
