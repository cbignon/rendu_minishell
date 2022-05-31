/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:03:43 by atron             #+#    #+#             */
/*   Updated: 2022/04/28 10:54:59 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESSES_INTERNAL_H
# define PROCESSES_INTERNAL_H

# include "processes.h"
# include <stdlib.h>
# include "libft.h"
# include "utils.h"
# include "ft_split.h"
# include "env.h"

t_bool	is_redir(char *arg);
int		arg_count_no_redir(char **args);
char	**get_real_args(char **args);
int		get_redir_count(char **args);
int		get_trailing_count(char *str);
#endif
