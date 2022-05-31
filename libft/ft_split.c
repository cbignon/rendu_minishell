/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:27:08 by atron             #+#    #+#             */
/*   Updated: 2021/05/19 19:33:21 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_freetab(char **tab, size_t size)
{
	size_t	x;

	x = 0;
	while (x < size)
		ft_free((void *)&tab[x++], 0);
	ft_free((void *)&tab, 0);
	return (NULL);
}

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
			i++;
	}
	return (words);
}

static int	ft_next_word(char const *str, char c, int i)
{
	if (i == 0 && str[i] != c && str[i])
		return (i);
	while (str[i] != c && str[i])
		i++;
	while (str[i] == c && str[i])
		i++;
	return (i);
}

static int	ft_wlength(char const *str, char c, int i)
{
	int	length;

	length = 0;
	while (str[i + length] != c && str[i + length])
		length++;
	return (length + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;
	int		ind;
	int		i;
	int		j;

	words = ft_count_words(s, c);
	tab = (char **)gc_malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	i = -1;
	ind = 0;
	while (++i < words && s)
	{
		ind = ft_next_word(s, c, ind);
		j = 0;
		tab[i] = (char *)gc_malloc(sizeof(char) * ft_wlength(s, c, ind));
		if (!tab[i])
			return ((char **)ft_freetab(tab, i));
		while (s[ind] != c && s[ind])
			tab[i][j++] = s[ind++];
		tab[i][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
