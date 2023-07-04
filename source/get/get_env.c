/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:47:20 by bberger           #+#    #+#             */
/*   Updated: 2023/06/15 14:17:24 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**get_env_variables(t_env *env)
{
	if (env->env_vars)
		remove_env_vars(env);
	env->env_vars = variable_list_to_array(env);
	return (env->env_vars);
}

char	**get_env_bins(t_env *env)
{
	char	*path;
	char	**bins;

	path = get_env_var_value_with_name(env, "PATH");
	if (!path)
		return (NULL);
	bins = ft_split(path, ':');
	return (bins);
} 

t_line	*get_first_line(t_env *env)
{
	if (env->first_line)
		return (env->first_line);
	return (0);
}
