/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classification.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:30:40 by bberger          #+#    #+#             */
/*   Updated: 2023/10/05 16:11:02 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redirection_classification(t_env *env, char *line, int index)
{
	t_token	*token;
	int		new_index;

	new_index = redirection_detection(line, index);
	token = create_token_redir(line, index, new_index);
	add_token_list(env, token);
	index = arg_redirect_extraction(env, token, line, new_index);
	return (index);
}

int	word_classification(t_env *env, char *line, int index)
{
	char	*content;
	int		new_index;
	t_token	*token;

	new_index = word_detection(env, line, index);
	content = malloc_substrcpy(line, index, new_index);
	if (is_cmd(env, content))
	{
		new_index = cmd_tokenizer(env, line, content, ++new_index);
	}
	else
	{
		token = word_tokenizer(content, TOKEN_WORD);
		add_token_list(env, token);
	}
	return (new_index);
}
// word_detection: gives the index of the str where a word is
// is_cmd: check if str is a built in or 

t_token	*cmd_classification(t_env *env, char *content)
{
	t_token	*token;

	token = NULL;
	if (is_built_in(content))
	{
		token = cmd_tokenization(content, TOKEN_BUILT_IN);
	}
	else if (is_bin(env, content))
	{
		token = cmd_tokenization(content, TOKEN_BINARY);
	}
	return (token);
}
// check if content is a built_in
// or if it is a bin (env and path ave a name and a value)  , then initialize token

int	arg_classification(t_env *env, t_cmd *cmd, char *line, int index)
{
	int		new_index;

	new_index = index;
	if (is_blank_argument(env, line, index))
	{
		new_index = blank_arg_tokenizer(env, cmd, line, index);
	}
	else if (is_single_quote(line[index]))
	{
		new_index = single_tokenizer(cmd, line, index);
	}
	else if (is_double_quote(line[index]))
	{
		new_index = double_tokenizer(env, cmd, line, index);
	}
	else if (is_variable_word(line, index))
	{
		new_index = variable_tokenizer(env, cmd, line, index);
	}
	else if (is_word(env, line, index))
	{
		new_index = word_arg_extraction(env, cmd, line, index);
	}
	return (new_index);
}
