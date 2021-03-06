/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_use.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:17:30 by atron             #+#    #+#             */
/*   Updated: 2022/06/08 06:23:13 by Darkkoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gc	*get_garbage_collection(void)
{
	static t_gc	gc = {NULL};

	return (&gc);
}

void	gc_init(void)
{
	get_garbage_collection();
}

void	*gc_malloc(size_t size)
{
	t_gc	*gc;
	void	*ptr;
	void	*res;

	gc = get_garbage_collection();
	if (!gc)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	res = ft_lstnew(ptr);
	if (!res)
	{
		ft_free(ptr, 0);
		return (NULL);
	}
	ft_lstadd_front(&gc->ptr_list, res);
	return (ptr);
}

int	gc_delone(void **ptr, int out)
{
	t_gc	*gc;
	t_list	*prev;
	t_list	*next;
	t_list	*current;

	gc = get_garbage_collection();
	if (!gc)
		return (-1);
	prev = gc->ptr_list;
	current = ft_lstfind(&prev, &next, *ptr);
	if (!current)
		return (-1);
	if (prev == current)
	{
		gc->ptr_list = current->next;
		ft_lstdelone(current, &free);
		*ptr = NULL;
		return (out);
	}
	prev->next = next;
	ft_lstdelone(current, &free);
	*ptr = NULL;
	return (out);
}

int	gc_clear(int out)
{
	t_gc	*gc;

	gc = get_garbage_collection();
	if (!gc)
		return (1);
	ft_lstclear(&gc->ptr_list, &free);
	return (out);
}
