/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:22:28 by bberger          #+#    #+#             */
/*   Updated: 2022/10/05 17:07:10 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_all_line(t_env *env)
{
	t_line	*line;

	line = get_first_line(env);
	while (line)
	{
		print_line(line);
		line = line->next;
	}
}

void	print_line(t_line *line)
{
	ft_printf("Line [%d] : [%s]\n", line->index, line->content);
}
