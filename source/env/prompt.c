/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:17:13 by bberger          #+#    #+#             */
/*   Updated: 2023/10/05 17:07:14 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	prompt(t_env	*env)
{
	char	*read_line;

	while (1)
	{
		use_signal();
		read_line = get_line();
		if (!read_line)
		{
			ft_printf("exit\n");
			break ;
		}
		if (line_is_not_empty(read_line))
			execute_line(env, read_line);
		free(read_line);
	}
}
// use_signal lance pass et call_prompt
// line_is_not_empty check si on a depasse le dernier caractere
// execute_line: 



void	create_history(char *line)
{
	int	fd;

	add_history(line);
	fd = open("history.log", O_CREAT | O_WRONLY | O_APPEND, 0777);
	write_line(line, fd);
}
// add_history belongs to read_line lib


void	write_line(char *line, int fd)
{
	ft_putstr_fd(line, fd);
	ft_putstr_fd("\n", fd);
}
