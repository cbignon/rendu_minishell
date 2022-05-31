/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:36:11 by cbignon           #+#    #+#             */
/*   Updated: 2022/02/16 11:30:26 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_internal.h"

void	**ft_sort_tab(void **tab, int tab_len)
{
	int		i;
	char	*tmp;
	int		sorted;

	i = 0;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = -1;
		while (++i < (tab_len - 1))
		{
			if (ft_strncmp(tab[i], tab[i + 1], ft_strlen(tab[i])) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				sorted = 0;
			}
		}
	}
	return (tab);
}
