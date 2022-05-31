/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_use.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:17:30 by atron             #+#    #+#             */
/*   Updated: 2022/04/22 16:05:51 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gc	**get_garbage_collection(void)
{
	static t_gc	*gc;

	if (!gc)
	{
		gc = (t_gc *)malloc(sizeof(t_gc));
		gc->ptr_list = NULL;
	}
	return (&gc);
}

void	gc_init(void)
{
	get_garbage_collection();
}

void	*gc_malloc(size_t size)
{
	t_gc	**gc;
	void	*ptr;

	ptr = malloc(size);
	gc = get_garbage_collection();
	if (!ptr)
		return (NULL);
	ft_lstadd_front(&(*gc)->ptr_list, ft_lstnew(ptr));
	return (ptr);
}

int	gc_delone(void **ptr, int out)
{
	t_gc	**gc;
	t_list	*prev;
	t_list	*next;
	t_list	*current;

	gc = get_garbage_collection();
	prev = (*gc)->ptr_list;
	current = ft_lstfind(&prev, &next, *ptr);
	if (!current)
		return (-1);
	if (prev == current)
	{
		(*gc)->ptr_list = current->next;
		ft_lstdelone(current, &free);
		return (out);
	}
	prev->next = next;
	ft_lstdelone(current, &free);
	*ptr = NULL;
	return (out);
}

int	gc_clear(int out)
{
	t_gc	**gc;

	gc = get_garbage_collection();
	ft_lstclear(&(*gc)->ptr_list, &free);
	ft_free((void **)gc, 0);
	return (out);
}
