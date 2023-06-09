/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:52:44 by bberger          #+#    #+#             */
/*   Updated: 2023/09/28 07:15:36 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_token_word(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_WORD)
		return (1);
	return (0);
}

int	is_token_file(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_FILE)
		return (1);
	return (0);
}

int	is_token_output_chevron(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_OUTPUT_CHEVRON)
		return (1);
	return (0);
}

int	is_token_basic_redirection(t_token *token)
{
	if (!token)
		return (0);
	if (is_token_output_chevron(token) || is_token_input_chevron(token)
		|| is_token_append_chevron(token))
		return (1);
	return (0);
}

int	is_redir_heredoc(t_redir *redir)
{
	if (!redir)
		return (0);
	if (redir->type == TOKEN_HERE_DOC)
		return (1);
	return (0);
}
