/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:14:04 by atron             #+#    #+#             */
/*   Updated: 2022/02/11 15:37:13 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list **prev, t_list **next, void *ptr)
{
	t_list	*current;

	if (!prev || !*prev || !ptr)
		return (NULL);
	if ((*prev)->content == ptr)
		return (*prev);
	current = (*prev)->next;
	while (current)
	{
		*next = current->next;
		if (current->content == ptr)
			return (current);
		*prev = current;
		current = *next;
	}
	return (NULL);
}
