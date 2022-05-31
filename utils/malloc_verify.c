/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_verify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:02:27 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/25 16:25:44 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_internal.h"
#include "env.h"
#include "core.h"

void	*malloc_verify(int size)
{
	void		*ptr;

	ptr = gc_malloc(size);
	verify_ptr(ptr);
	return (ptr);
}

void	verify_ptr(void *ptr)
{
	if (!ptr)
		ft_exit("MALLOC ERROR!\n", 3, 2);
}

void	*malloc_bzero(int size)
{
	void	*ptr;

	ptr = malloc_verify(size);
	verify_ptr(ptr);
	ft_bzero(ptr, size);
	return (ptr);
}
