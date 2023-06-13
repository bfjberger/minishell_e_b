/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:56:49 by bberger          #+#    #+#             */
/*   Updated: 2023/10/05 17:07:10 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_error_token_cmd(t_token *token)
{
	t_cmd	*cmd;
	t_cmd	*next_cmd;
	t_cmd	*prev_cmd;
	int		result;

	result = 0;
	cmd = get_class(token);
	if (is_token_cmd(token->next))
	{
		next_cmd = get_class(token->next);
		ft_printf("Error : [Two following cmd \"%s\" && \"%s\"]\n",
			cmd->content, next_cmd->content);
		result += 1;
	}
	else if (is_token_cmd(token->prev))
	{
		prev_cmd = get_class(token->prev);
		ft_printf("Error : [Two following cmd \"%s\" && \"%s\"]\n",
			prev_cmd->content, cmd->content);
		result += 1;
	}
	if (is_cmd_built_in(cmd))
		result += check_error_built_in(cmd);
	return (result);
}
