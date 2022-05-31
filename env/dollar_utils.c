/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:14:45 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/27 14:04:24 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

int	count_dollar(char *str, int size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i] && i < size)
	{
		if (str[i] == '$')
			count++;
		i++;
	}
	return (count);
}

int	count_dollar_protect(char *s)
{
	int	count;
	int	i;
	int	dq;

	count = 0;
	i = 0;
	dq = ft_str_has_char(s, '\"');
	if (dq == -1)
		return (count_dollar(s, ft_strlen(s)));
	while (s[i])
	{
		if (s[i] == '\"')
		{
			if (ft_str_has_char((s + i), '$') != -1)
				count++;
			i += ft_strclen(s + i + 1, '\"');
		}
		else if (s[i] == '$')
			count++;
		i++;
	}
	return (count);
}

int	get_dollar_len(char *str, int start)
{
	int	i;
	int	j;

	i = start;
	j = 0;
	if (str[start] == '\"')
	{
		start++;
		i++;
	}
	while (str[i])
	{
		if (i > start && str[i] == '$')
			break ;
		if (str[i] == ' ' || str[i] == '\'' || str[i] == '\"')
			break ;
		i++;
		j++;
	}
	return (j);
}

int	ft_str_has_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] && str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_is_valid_var_char(char c)
{
	if (c == '_' || ft_isalnum(c) || c == '?')
		return (1);
	return (0);
}
