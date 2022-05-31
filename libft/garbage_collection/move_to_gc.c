/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_gc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:39:09 by atron             #+#    #+#             */
/*   Updated: 2022/04/28 11:20:49 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*move_to_gc(void **ptr, size_t size)
{
	void	*out;

	if (!ptr || !*ptr)
		return (NULL);
	out = (char *)gc_malloc(size);
	ft_memmove(out, *ptr, size);
	ft_free(ptr, 0);
	return (out);
}
