/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:36:13 by bberger           #+#    #+#             */
/*   Updated: 2023/06/09 17:34:17 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	line_is_finish(char *line, int index)
{
	if (index >= ft_strlen(line) && is_finish(line[index]))
		return (1);
	return (0);
}

int	line_is_not_finish(char *line, int index)
{
	if (index < ft_strlen(line) && is_not_finish(line[index]))
		return (1);
	return (0);
}

int	line_is_empty(char	*line)
{
	if (ft_strlen(line) == 0)
		return (1);
	else
		return (0);
}

int	line_is_not_empty(char	*line)
{
	if (ft_strlen(line) > 0)
		return (1);
	return (0);
}

int	is_dollar_word(t_env *env, char *line, int i)
{
	if (line[i] == '$' && is_argument_separator(env, line, i))
		return (1);
	return (0);
}
