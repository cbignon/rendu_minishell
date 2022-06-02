/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:22:02 by atron             #+#    #+#             */
/*   Updated: 2022/06/02 12:59:48 by Darkkoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_internal.h"

t_bool	is_meta(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (TRUE);
	return (FALSE);
}

t_bool	verify_meta(char *str, int index)
{
	int		num;
	char	c;
	//int		index2;

	//index2 = index;
	num = ft_chara_count(&str[index]);
	if ((str[index] == '>' || str[index] == '<') && num > 2)
		return (FALSE);
	if (str[index] == '|' && num > 1)
		return (FALSE);
	c = str[index];
	while (str[index] && str[index] == c)
		index++;
	while (str[index] == ' ')
		index++;
	if (is_meta(str[index]))
		return (FALSE);
	return (TRUE);
}

t_bool	is_quote(char c)
{
	if (c == '\"' || c == '\'')
		return (TRUE);
	return (FALSE);
}

int	space_str(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (2);
}

int	verify_syntax(char *cmd)
{
	int	index;
	int	tmp;

	index = ft_strlen(cmd) - 1;
	if (space_str(cmd) == 2)
		return (2);
	if (is_meta(cmd[index]))
		return (1);
	if (cmd[0] == '|') //TODO: skip spaces
		return (-1);
	index = 0;
	while (cmd[index])
	{
		if (is_quote(cmd[index]))
		{
			tmp = get_closing_quote(&cmd[index], cmd[index]);
			if (!tmp)
				return (1);
			index += tmp;
		}
		else if (is_meta(cmd[index]))
			if (!verify_meta(cmd, index))
				return (-1);
		index++;
	}
	return (0);
}
