/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:23:24 by atron             #+#    #+#             */
/*   Updated: 2022/06/02 13:26:07 by Darkkoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_INTERNAL_H
# define CORE_INTERNAL_H

# include "processes.h"
# include "utils.h"
# include "libft.h"
# include "env.h"
# include "core.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/wait.h>
# include <errno.h>
# include <sys/stat.h>

/*******************************************************************************
 * EXEC_CMD.C 
 */
void	ft_export_res(int ret);
void	exec_cmd(t_process *p);

/*******************************************************************************
 * EXEC_UTILS.C 
 */
int		launch_builtin(t_process *p);
int		ft_is_builtin(char *cmd);

/*******************************************************************************
 * PIPE.C 
 */
int		create_pipe(t_process *processes);

/*******************************************************************************
 * FT_GET_BIN_PATH.C 
 */
char	*ft_get_bin_path(char *cmd, char **env);
char	*get_full_binpath(char *dir, DIR *dp, struct dirent *dirp);
void	ft_exec_bin(t_process *p);

/*******************************************************************************
 * PATH.C 
 * ft_get_path from environment, in a char**
 * find_in_path open and read every directory, return the full path to the cmd
 */
char	**ft_get_path(char **env);
char	*find_in_path(char **path, char *cmd);

/*******************************************************************************
 * CLOSE_FD.C 
 * */
int		close_fd(t_process *p);

/*******************************************************************************
 * REDIRECT.C 
 * */
void	setup_redirect(t_process *p);
char	*get_stdin(char *delim, int *val, t_bool quoted);

/*******************************************************************************
 * HEREDOC.C 
 * */
void	create_heredoc(t_process *p, int index, int heredoc_nb);
void	setup_heredoc(t_process *p);
void	setup_heredocs(t_process *processes);
#endif
