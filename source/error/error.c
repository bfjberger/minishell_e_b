/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:35:14 by bberger          #+#    #+#             */
/*   Updated: 2022/10/05 17:07:10 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_error_parsing(t_env *env)
{
	t_token	*token;

	token = get_first_token(env);
	while (token)
	{
		if (is_token_cmd(token))
		{
			env->error_parsing += check_error_token_cmd(token);
		}
		if (is_token_redirection(token))
		{
			env->error_parsing += check_error_token_redirection(token);
		}
		if (is_token_word(token))
		{
			env->error_parsing += check_error_token_word(env, token);
		}
		token = token->next;
	}
}
// initie la struct token, first token est un pointer sur la struc token
// is_token_cmd verifie si token est une commande, voir la liste des paramettrage du .h
// meme idee pour les mots et pour les redirections
// check_error_token_cmd 

int	check_error_token_word(t_env *env, t_token *token)
{
	t_word	*word;

	word = get_class(token);
	ft_printf("Error : [Unknow token \"%s\"]\n", word->content);
	update_variable_status_process(env, 127);
	return (1);
}
