/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:15:36 by atron             #+#    #+#             */
/*   Updated: 2022/04/28 16:12:19 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split_internal.h"

int	get_numbered_redirect(char *str)
{
	int	index;

	index = 0;
	while (str[index] && str[index] != '|'
		&& str[index] != ' ' && str[index] != '\''
		&& str[index] != '\"')
	{
		if (!ft_isdigit(str[index]) && str[index] != '>' && str[index] != '<')
			return (0);
		if (str[index] == '>' || str[index] == '<')
			return (index + ft_chara_count(&str[index]));
		index++;
	}
	return (index);
}

int	pass_white_space(int i, char *str)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

int	get_arg_length(char *str, int length)
{
	int	tmp;

	if (ft_isdigit(str[length]) || str[length] == '<' || str[length] == '>')
	{
		length = get_numbered_redirect(&str[length]);
		if (length)
			return (length);
	}
	if (is_quote(str[length]))
	{
		tmp = get_closing_quote(str + length, str[length]) + 1;
		if (tmp && (!str[length + tmp] || str[length + tmp] == ' '))
			return (tmp);
		length = tmp;
	}
	while (str[length] && str[length] != '<'
		&& str[length] != '>' && str[length] != ' ')
	{
		if (is_quote(str[length]))
			length += get_closing_quote(str + length, str[length]) + 1;
		else
			length++;
	}
	return (length);
}
