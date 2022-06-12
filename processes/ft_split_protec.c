/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_protec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:27:08 by atron             #+#    #+#             */
/*   Updated: 2022/06/12 14:32:57 by Darkkoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "processes_internal.h"

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			words++;
		while (str[i] != c && str[i])
		{
			if (str[i] == '"' || str[i] == '\'')
				i += get_closing_quote(&str[i], str[i]);
			i++;
		}
	}
	return (words);
}

static int	ft_wlength(char const *str, char c, int i)
{
	int	length;

	length = 0;
	while (str[i + length] != c && str[i + length])
	{
		if (str[i + length] == '"' || str[i + length] == '\'')
				length += get_closing_quote(&str[i + length], str[i + length]);
		length++;
	}
	printf("wlength: %d\n", length);
	return (length);
}

#include <unistd.h>

char	**ft_split_protec(char const *s, char c)
{
	char	**tab;
	int		words;
	int		ind;
	int		i;
	int		j;

	words = ft_count_words(s, c);
	tab = (char **)malloc_verify(sizeof(char *) * (words + 1));
	i = -1;
	ind = 0;
	while (++i < words && s)
	{
		j = ft_wlength(s, c, ind);
		tab[i] = (char *)malloc_verify(sizeof(char) * j);
		tab[i] = ft_substr_cu(s, ind, j);
		ind += j + 1;
	}
	tab[i] = NULL;
	return (tab);
}
