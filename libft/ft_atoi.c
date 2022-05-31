/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 21:22:28 by atron             #+#    #+#             */
/*   Updated: 2022/04/28 11:11:21 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	check_int_min(char *num)
{
	int	x;

	x = -1;
	if (is_full_digit(num))
		return (TRUE);
	if (num[0] != '-')
		return (FALSE);
	if (ft_strlen(num) > ft_strlen(INT_MIN_STR))
		return (FALSE);
	if (ft_strlen(num) < ft_strlen(INT_MIN_STR) && is_full_digit(num + 1))
		return (TRUE);
	if (!is_full_digit(num + 1))
		return (FALSE);
	while (++x < (int)ft_strlen(num + 1))
	{
		if (num[x + 1] < INT_MIN_STR[x + 1])
			return (TRUE);
		else if (num[x + 1] > INT_MIN_STR[x + 1])
			return (FALSE);
	}
	return (TRUE);
}

t_bool	check_int_max(char *num)
{
	int	x;

	x = -1;
	if (num[0] == '-')
		return (TRUE);
	if (ft_strlen(num) > ft_strlen(INT_MAX_STR))
		return (FALSE);
	if (ft_strlen(num) < ft_strlen(INT_MAX_STR) && is_full_digit(num))
		return (TRUE);
	if (!is_full_digit(num))
		return (FALSE);
	while (++x < (int)ft_strlen(num))
	{
		if (num[x] < INT_MAX_STR[x])
			return (TRUE);
		else if (num[x] > INT_MAX_STR[x])
			return (FALSE);
	}
	return (TRUE);
}

t_bool	check_int_limits(char *num)
{
	if (check_int_max(num) && check_int_min(num))
		return (TRUE);
	return (FALSE);
}

t_bool	check_uint_limits(char *num)
{
	int	x;

	x = 0;
	if (!is_full_digit(num))
		return (FALSE);
	if (ft_strlen(num) > ft_strlen(UINT_MAX_STR))
		return (FALSE);
	while (++x < (int)ft_strlen(num))
	{
		if (num[x] < INT_MAX_STR[x])
			return (TRUE);
		else if (num[x] > INT_MAX_STR[x])
			return (FALSE);
	}
	return (TRUE);
}

t_bool	ft_atoi(char *str, int *out)
{
	long int	res;
	int			sign;

	if (!out)
		return (FALSE);
	res = 0;
	sign = 1;
	while ((*str <= 13 && *str >= 9) || *str == ' ')
		str++;
	if (*str == '-')
		sign *= -1;
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			res = res * 10 + (*str++ - '0');
		else
			break ;
	}
	*out = (int)(res * sign);
	return (TRUE);
}
