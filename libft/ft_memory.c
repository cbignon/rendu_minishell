/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:58:38 by atron             #+#    #+#             */
/*   Updated: 2021/05/11 11:19:04 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_free(void **ptr, int out)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (out);
}
