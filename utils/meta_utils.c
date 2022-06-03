/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:11:31 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/03 14:11:58 by cbignon          ###   ########.fr       */
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
