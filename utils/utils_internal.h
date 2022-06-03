/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:06:09 by atron             #+#    #+#             */
/*   Updated: 2022/06/03 14:14:30 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_INTERNAL_H
# define UTILS_INTERNAL_H

# include "libft.h"
# include "utils.h"
# include <readline/readline.h>
# include <stdlib.h>
# include <readline/history.h>
# include <dirent.h>

t_bool	verify_meta(char *str, int index);
t_bool	is_meta(char c);
#endif
