/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:44:46 by bberger          #+#    #+#             */
/*   Updated: 2023/09/26 17:45:36 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_env_var_value_with_name(t_env *env, char *name, char *value)
{
	t_var	*var;

	var = get_env_var_with_name(env, name);
	if (!var)
		return ;
	change_env_var_value(var, value);
}

void	change_env_var_value(t_var *var, char *new_value)
{
	if (var->value)
		free(var->value);
	var->value = new_value;
	var->id = VALUE;
}
