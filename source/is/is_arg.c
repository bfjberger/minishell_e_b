/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:58:36 by bberger          #+#    #+#             */
/*   Updated: 2023/09/26 15:53:24 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_arg_variable(t_arg *arg)
{
	if (!arg)
		return (0);
	if (arg->id == TOKEN_VARIABLE)
		return (1);
	return (0);
}

int	is_arg_flags(t_arg *arg)
{
	if (!arg)
		return (0);
	if (arg->id == TOKEN_FLAGS)
		return (1);
	return (0);
}

int	is_arg_blank(t_arg *arg)
{
	if (!arg)
		return (0);
	if (arg->id == TOKEN_BLANK)
		return (1);
	return (0);
}
