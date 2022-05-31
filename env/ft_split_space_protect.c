/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space_protect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:28:22 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/26 17:00:55 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

static int	get_word_len_quote(char *str, int *i, int *ret, int *size)
{
	if (str[*i] == '\'')
	{
		*size = ft_strclen(str + *i + 1, '\'') + 2;
		if (str[*i + *size] == ' ' || str[*i + *size] == '\0')
			return (1);
		*ret += *size;
		*i += *size;
		return (0);
	}
	if (str[*i] == '\"')
	{
		*size = ft_strclen(str + *i + 1, '\"') + 2;
		if (str[*i + *size] == ' ' || str[*i + *size] == '\0')
			return (1);
		*ret += *size;
		*i += *size;
		return (0);
	}
	return (0);
}

static int	get_len(char *str, int *i, int *ret)
{
	while (str[*i] == ' ')
		(*i)++;
	if (first_space_or_quote(str, *i) == 1)
	{
		while (str[(*i)] && str[(*i)++] != ' ')
			(*ret)++;
		return (1);
	}
	else if (first_space_or_quote(str, *i) == 2)
	{
		while (str[*i] && str[*i] != '\'' && str[*i] != '\"')
		{
			(*ret)++;
			(*i)++;
		}
		return (0);
	}
	return (0);
}

static int	get_word_len_protect(char *str, int i, int ret, int size)
{
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (get_word_len_quote(str, &i, &ret, &size) == 1)
				return (ret + size);
		}
		else
		{
			if (get_len(str, &i, &ret) == 1)
				return (ret);
			else
				continue ;
		}
	}
	return (ret);
}

char	**split_protect_quoted(char *str, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		len;
	int		count_words;

	count_words = count_words_protected(str, c, 0, 0);
	tab = malloc_verify(sizeof(char *) * (count_words + 1));
	i = 0;
	j = 0;
	while (str[i] && j < count_words)
	{
		len = 0;
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			len = get_word_len_protect(str, i, 0, 0);
			tab[j] = ft_substr_cu(str, i, len);
			j++;
			i += len;
		}
	}
	tab[j] = NULL;
	return (tab);
}
