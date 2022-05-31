/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:49:23 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/22 16:05:38 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_internal.h"

int	size_tab_to_str(char **tab)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (tab[i])
	{
		size += ft_strlen(tab[i]) + 1;
		i++;
	}
	return (size);
}

char	*ft_tab_to_str(char **tab, char c, int final_len)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	str = malloc_verify(sizeof(char) * (final_len + ft_tablen(tab) + 1));
	i = 0;
	j = 0;
	k = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			str[k] = tab[i][j];
			k++;
			j++;
		}
		if (ft_tablen(tab) > 1 && i < (ft_tablen(tab) - 1))
			str[k++] = c;
		i++;
	}
	str[k] = '\0';
	return (str);
}

char	*ft_tab_to_simple_str(char **tab)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	str = malloc_verify((sizeof(char) * (size_tab_to_str(tab)
					+ ft_tablen(tab) + 2)));
	i = 0;
	j = 0;
	k = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			str[k] = tab[i][j];
			k++;
			j++;
		}
		i++;
	}
	str[k] = '\0';
	return (str);
}
