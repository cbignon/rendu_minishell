/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:46:58 by atron             #+#    #+#             */
/*   Updated: 2022/06/03 13:32:57 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_internal.h"

char	**ft_tabcpy(char **tab)
{
	int		size;
	char	**out;
	int		index;

	index = 0;
	size = ft_tablen(tab);
	out = (char **)malloc_verify(sizeof(char *) * (size + 1));
	if (!out)
		return (NULL);
	while (index < size)
	{
		out[index] = tab[index];
		index++;
	}
	out[index] = 0;
	return (out);
}

char	**ft_tabncpy(char **tab, int n)
{
	char	**out;
	int		index;

	index = 0;
	out = (char **)malloc_verify(sizeof(char *) * (n + 1));
	if (!out)
		return (NULL);
	while (index < n)
	{
		out[index] = tab[index];
		index++;
	}
	out[index] = 0;
	return (out);
}

char	**ft_tabdup(char **tab)
{
	char	**dup;
	int		len;
	int		i;

	if (!tab)
		return (NULL);
	len = (int)ft_tablen(tab);
	dup = (char **)malloc_verify_ncu(sizeof(char *) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = ft_strdup(tab[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

char	**ft_tabdup_cu(char **tab)
{
	char	**dup;
	int		len;
	int		i;

	if (!tab)
		return (NULL);
	len = (int)ft_tablen(tab);
	dup = (char **)malloc_verify(sizeof(char *) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = ft_strdup_cu(tab[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
