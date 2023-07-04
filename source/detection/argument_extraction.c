/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_extraction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:13:01 by bberger           #+#    #+#             */
/*   Updated: 2023/06/20 15:35:21 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	argument_extraction(t_env *env, t_cmd *cmd, char *line, int index)
{
	int	new_index;

	new_index = index;
	if (is_flags(line, index))
	{
		new_index = flags_tokenizer(env, cmd, line, index);
		index = new_index;
	}
	while (line_is_not_finish(line, index) && !(is_separator(line, index)))
	{
		new_index = arg_classification(env, cmd, line, index);
		index = new_index;
		index++;
	}
	return (new_index);
}
// on trie les arguments
// if we have a flag, flags_tokenizer ajoute le flag a la liste     
//   
