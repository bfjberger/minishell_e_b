/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:30:32 by bberger          #+#    #+#             */
/*   Updated: 2022/09/28 18:00:41 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_argument(char *line, int i)
{
	if (!(is_separator(line, i)) && !(is_blank(line[i])))
		return (1);
	return (0);
}

int	is_flags(char *line, int i)
{
	if (index_is_over_flow(line, i))
		return (0);
	if (line[i] == '-' && !(is_blank(line[i + 1])) && line[i + 1] == 'n')
		return (1);
	return (0);
}
