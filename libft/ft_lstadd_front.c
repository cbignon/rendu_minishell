/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 12:14:34 by atron             #+#    #+#             */
/*   Updated: 2020/12/12 11:39:59 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *element)
{
	if (!alst || !element)
		return ;
	if (*alst)
		element->next = *alst;
	else
		element->next = NULL;
	*alst = element;
}
