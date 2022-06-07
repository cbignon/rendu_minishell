/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_in_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:43:53 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/07 12:27:26 by Darkkoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_internal.h"

char	*ft_find_in_tab(char **tab_str, char *str)
{
	int		i;
	int		j;

	i = 0;
	if (!str || str[0] == '\0' || !tab_str)
		return (NULL);
	while (tab_str[i])
	{
		j = 0;
		while (tab_str[i][j])
		{
			if (tab_str[i][j] != str[j])
			{
				if (!str[j])
					return (tab_str[i]);
				break ;
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*ft_start_with(char *str, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (str[i] != s[i])
			return (NULL);
		i++;
	}
	return (str);
}
