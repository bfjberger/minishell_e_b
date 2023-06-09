/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:11:21 by bberger           #+#    #+#             */
/*   Updated: 2022/10/05 16:10:29 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_separator(char *line, int i)
{
	if (index_is_over_flow(line, i))
		return (0);
	if (is_redirection(line, i) || is_blank_before_finish(line, i))
		return (1);
	return (0);
}
// index_is_over_flow check si index est sup au strlen de la str
// is_redirection check si le caractere est un pipe chevron ou heredoc

int	is_delimiter(t_env *env, char *line, int index)
{
	if (is_blank(line[index]) || is_separator(line, index)
		|| is_variable(env, line, index))
		return (1);
	return (0);
}
// 


int	is_variable_delimiter(char *line, int index)
{
	if (is_blank(line[index]) || is_separator(line, index)
		|| line[index] == '$' || is_finish(line[index])
		|| is_quote(line[index]))
		return (1);
	return (0);
}

int	is_argument_separator(t_env *env, char *line, int index)
{
	if (is_separator(line, index) || is_variable(env, line, index))
		return (1);
	return (0);
}

int	is_word_argument_separator(t_env *env, char *line, int index)
{
	if (is_argument_separator(env, line, index) || is_quote(line[index])
		|| is_blank(line[index]))
		return (1);
	return (0);
}
