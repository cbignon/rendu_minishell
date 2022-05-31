/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_protect_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:59:19 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/26 17:01:06 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

static void	count_words_quoted(char *str, char c, int *word, int *i)
{
	if (str[*i] == '\'')
		(*i) += ft_strclen(str + ((*i) + 1), '\'') + 2;
	else if (str[*i] == '\"')
		(*i) += ft_strclen(str + ((*i) + 1), '\"') + 2;
	if (str[*i] == c || str[*i] == '\0')
		(*word)++;
}

int	count_words_protected(char *str, char c, int word, int i)
{
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			count_words_quoted(str, c, &word, &i);
		else
		{
			while (str[i] == c)
				i++;
			if (str[i] && str[i] != c && str[i] != '\'' && str[i] != '\"')
			{
				if (first_space_or_quote(str, i) == 1)
					word++;
				else
					i++;
			}
			while (str[i] && str[i] != c && str[i] != '\'' && str[i] != '\"')
				i++;
		}
	}
	return (word);
}
