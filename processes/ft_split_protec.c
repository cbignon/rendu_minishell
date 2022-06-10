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
#include "processes_internal.h"

// static void	*ft_freetab(char **tab, size_t size)
// {
// 	size_t	x;

// 	x = 0;
// 	while (x < size)
// 		gc_delone((void *)&tab[x++], 0);
// 	gc_delone((void *)&tab, 0);
// 	return (NULL);
// }

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

// static int	ft_next_word(char const *str, char c, int i)
// {
// 	if (i == 0 && str[i] != c && str[i])
// 		return (i);
// 	while (str[i] != c && str[i])
// 	{
// 		if (str[i] == '"' || str[i] == '\'')
// 				i += get_closing_quote(&str[i], str[i]);
// 		i++;
// 	}
// 	while (str[i] == c && str[i])
// 		i++;
// 	return (i);
// }

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
	return (length + 1);
}

char	**ft_split_protec(char const *s, char c)
{
	char	**tab;
	int		words;
	int		ind;
	int		i;
	int		j;

	words = ft_count_words(s, c);
	printf("count words: %d\n", words);
	tab = (char **)malloc_verify(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	i = -1;
	ind = 0;
	while (++i < words && s)
	{
		// ind += ft_next_word(s, c, ind);
		printf("index: %d\n", ind);
		j = ft_wlength(s, c, ind);
		tab[i] = (char *)malloc_verify(sizeof(char) * j);
		tab[i] = ft_substr_cu(s, ind, j);
		ind += j;
	}
	tab[i] = NULL;
	return (tab);
}
