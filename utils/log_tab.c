/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:04:17 by atron             #+#    #+#             */
/*   Updated: 2022/04/20 11:32:52 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_internal.h"

void	log_tab(char **tab)
{
	int	index;

	index = 0;
	if (!tab)
		return ;
	while (tab[index])
	{
		printf("					%s\n", tab[index]);
		index++;
	}
}
