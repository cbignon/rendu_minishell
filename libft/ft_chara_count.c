/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chara_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:40:29 by atron             #+#    #+#             */
/*   Updated: 2022/02/24 13:43:22 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_chara_count(char *str)
{
	int		index;
	char	c;

	if (!str)
		return (0);
	index = 0;
	c = str[0];
	while (str[index] && str[index] == c)
		index++;
	return (index);
}
