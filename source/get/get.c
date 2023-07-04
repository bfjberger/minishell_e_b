/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:11:56 by bberger           #+#    #+#             */
/*   Updated: 2023/06/15 15:20:48 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env_var_value_with_name(t_env *env, char *name)
{
	t_var	*var;

	var = get_first_env_var(env);
	if (!var)
		return (NULL);
	while (var)
	{
		if (same_name(var->name, name))
		{
			return (var->value);
		}
		var = var->next;
	}
	return (NULL);
}

t_var	*get_env_var_with_name(t_env *env, char *name)
{
	t_var	*var;

	var = get_first_env_var(env);
	if (!var)
		return (NULL);
	while (var)
	{
		if (same_name(name, var->name))
		{
			return (var);
		}
		var = var->next;
	}
	return (0);
}
// get_first_env_var check is firat env est diff de 0
// same_name check si name est le meme, sinon on passe au suivant. ici name est un point d interrogation

t_var	*get_first_env_var(t_env *env)
{
	if (env->first_var)
		return (env->first_var);
	return (0);
}

t_var	*get_last_env_var(t_env *env)
{
	t_var	*var;

	var = get_first_env_var(env);
	if (!var)
		return (NULL);
	while (var)
	{
		if (!var->next)
			return (var);
		var = var->next;
	}
	return (0);
}

int	get_env_var_size(t_env *env)
{
	t_var	*var;
	int		i;

	var = get_first_env_var(env);
	if (!var)
		return (0);
	i = 0;
	while (var)
	{
		i++;
		var = var->next;
	}
	return (i);
}
