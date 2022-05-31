/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:30:33 by atron             #+#    #+#             */
/*   Updated: 2022/04/28 11:12:06 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_memory_config	*get_mem_config(void)
{
	static t_memory_config	*conf;

	if (!conf)
	{
		conf = (t_memory_config *)malloc(sizeof(*conf));
		conf->ml = &malloc;
		conf->fr = &free;
	}
	return (conf);
}
