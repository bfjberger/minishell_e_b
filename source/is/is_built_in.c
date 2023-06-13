/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:06:27 by bberger          #+#    #+#             */
/*   Updated: 2023/09/26 16:01:58 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_echo(t_cmd *cmd)
{
	if (same_str("echo", cmd->content, ft_strlen("echo")))
		return (1);
	return (0);
}

int	is_cd(t_cmd *cmd)
{
	if (same_str("cd", cmd->content, ft_strlen("cd")))
		return (1);
	return (0);
}

int	is_pwd(t_cmd *cmd)
{
	if (same_str("pwd", cmd->content, ft_strlen("pwd")))
		return (1);
	return (0);
}

int	is_env(t_cmd *cmd)
{
	if (same_str("env", cmd->content, ft_strlen("env")))
		return (1);
	return (0);
}

int	is_export(t_cmd *cmd)
{
	if (same_str("export", cmd->content, ft_strlen("export")))
		return (1);
	return (0);
}
