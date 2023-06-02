/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:05:53 by bberger          #+#    #+#             */
/*   Updated: 2022/09/29 15:30:23 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	reset_counter_error(t_env *env)
{
	env->error_parsing = 0;
	env->error_processing = 0;
}

int	doesnt_have_error_parsing(t_env *env)
{
	if (env->error_parsing < 1)
		return (1);
	return (0);
}

int	doesnt_have_error_processing(t_env *env)
{
	if (env->error_processing == 0)
		return (1);
	return (0);
}
