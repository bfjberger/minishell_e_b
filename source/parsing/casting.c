/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:32:40 by bberger          #+#    #+#             */
/*   Updated: 2023/09/26 17:04:32 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*get_class(t_token *token)
{
	if (is_token_cmd(token))
	{
		return ((t_cmd *)token->class);
	}
	else if (is_token_redirection(token))
	{
		return ((t_redir *)token->class);
	}
	else if (is_token_file(token))
	{
		return ((t_file *)token->class);
	}
	else if (is_token_word(token))
	{
		return ((t_word *)token->class);
	}
	return (NULL);
}
