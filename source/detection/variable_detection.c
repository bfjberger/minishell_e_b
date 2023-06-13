/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_detection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:49:53 by bberger          #+#    #+#             */
/*   Updated: 2023/10/05 14:50:10 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	variable_detection(char *line, int index)
{
	int		end;

	end = index;
	if (line[index] == '$')
		return (index);
	index++;
	while (line[index])
	{
		if (is_variable_delimiter(line, index))
		{
			end = index - 1;
			break ;
		}
		index++;
	}
	if (is_variable_delimiter(line, index))
		end = index - 1;
	return (end);
}
