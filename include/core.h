/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:45:52 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/08 10:27:03 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "processes.h"
# include "utils.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include "signal.h"

char		*ft_get_bin_path(char *cmd, char **env);
char		*find_in_path(char **path, char *cmd);
const char	*get_prompt(void);
int			ft_is_builtin(char *cmd);
void		exec_cmd(t_process *p);
void		fork_cmd(t_process *p);
void		ft_export_res(int ret);
int			create_pipe(t_process *processes);
void		int_handler(int sig);
void		signal_init(t_bool is_exec);
void		kill_subs(void);
void		close_one_proc_fd(t_process *p);
void		clean_args_quotes(char **args);
void		clean_quotes(t_process *processes);
void		setup_heredoc(t_process *p);
void		setup_heredocs(t_process *processes);
char		*read_heredoc(int *val);

#endif
