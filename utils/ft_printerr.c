/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:26:07 by cbignon           #+#    #+#             */
/*   Updated: 2022/02/16 16:22:37 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/utils.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h>

int	ft_printerr(int std_out, char *cmd, char *arg, char *msg)
{
	ft_putstr_fd("minishell: ", std_out);
	ft_putstr_fd(cmd, std_out);
	ft_putstr_fd(": ", std_out);
	if (arg)
	{
		ft_putchar_fd('\'', std_out);
		ft_putstr_fd(arg, std_out);
		ft_putchar_fd('\'', std_out);
	}
	ft_putendl_fd(msg, std_out);
	return (1);
}
