/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_in_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:43:53 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/20 11:29:41 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_internal.h"

char	*ft_find_in_tab(char **tab_str, char *str)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	if (!str || str[0] == '\0' || !tab_str)
		return (NULL);
	len = ft_strlen(str);
	while (tab_str[i])
	{
		j = 0;
		while (tab_str[i][j] == str[j])
		{
			j++;
			if (j == len)
				return (tab_str[i]);
			if (tab_str[i][j] == '\0' || tab_str[i][j] != str[j])
				break ;
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
