/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:56:26 by bberger           #+#    #+#             */
/*   Updated: 2023/06/14 13:32:46 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_last_status(int bin_status, int ret_built_in)
{
	if (ret_built_in == -1)
		return (bin_status);
	else if (bin_status == -1)
		return (ret_built_in);
	return (0);
}

int	convert_status_process_value(int status)
{
	if (WIFSIGNALED(status))
		status = WEXITSTATUS(status);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	return (status);
}

void	update_variable_status_process(t_env *env, int status)
{
	t_var	*var;
	char	*value;

	value = ft_itoa(status);
	if (!value)
		return ;
	var = get_env_var_with_name(env, "?");
	if (!var)
	{
		free(value);
		return ;
	}
	change_env_var_value(var, value);
}
// status est fixe a 130
// change_env_var_value: on change la var par value


