/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_verify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:02:27 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/08 10:06:41 by Darkkoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*malloc_verify_ncu(int size)
{
	void		*ptr;

	ptr = malloc(size);
	verify_ptr(ptr);
	return (ptr);
}

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
	ft_bzero(ptr, size);
	return (ptr);
}
