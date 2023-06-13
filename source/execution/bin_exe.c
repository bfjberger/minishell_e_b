/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:36:01 by bberger          #+#    #+#             */
/*   Updated: 2023/10/05 08:44:16 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	bin_execution(t_env *env, t_cmd *cmd, char **variables)
{
	int		pid;
	char	*path;

	path = get_cmd_path(cmd);
	pid = fork();
	if (pid == 0)
	{
		if (cmd_have_standart_fd(cmd))
		{
			execve(path, get_cmd_args(cmd), variables);
			perror("Command failure : ");
			exit(1);
		}
		else
		{
			redirect_cmd(cmd);
			close_all_fd(env);
			execve(path, get_cmd_args(cmd), variables);
			perror("Command failure : ");
			exit(1);
		}
	}
	else
		cmd->pid = pid;
}
