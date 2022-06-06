/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:05:44 by root              #+#    #+#             */
/*   Updated: 2022/06/05 11:18:28 by Darkkoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static double_t	get_precision(char *tab[])
{
	size_t		i;
	double_t	result;

	result = 0;
	if (ft_tablen(tab) == 2)
	{
		result = (double_t)ft_atoll(tab[1]);
		i = 0;
		while (i++ < ft_strlen(tab[1]))
			result /= 10;
	}
	return (result);
}

t_double_result	ft_atof(char *str)
{
	t_double_result	result;
	double_t		precision;
	char			**tab;

	tab = ft_split(str, '.');
	if (!tab || ft_tablen(tab) > 2)
	{
		ft_tabfree((void ***)&tab, ft_tablen(tab), 0);
		result.result = FALSE;
		result.message = "Invalid string!";
		result.value = 0.0f;
		return (result);
	}
	result.value = (double_t)ft_atoll(tab[0]);
	precision = get_precision(tab);
	if (**tab == '-')
		result.value -= precision;
	else
		result.value += precision;
	result.result = TRUE;
	result.message = "OK";
	ft_tabfree((void ***)&tab, ft_tablen(tab), 0);
	return (result);
}
