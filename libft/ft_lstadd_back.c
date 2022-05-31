/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:20:03 by atron             #+#    #+#             */
/*   Updated: 2020/12/01 11:17:27 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *element)
{
	t_list		*begin;

	if (!alst || !element)
		return ;
	if (!*alst)
	{
		*alst = element;
		return ;
	}
	begin = (*alst);
	while (begin->next)
		begin = begin->next;
	begin->next = element;
}
