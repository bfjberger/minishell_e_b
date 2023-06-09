/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:17:13 by bberger          #+#    #+#             */
/*   Updated: 2023/06/05 17:07:14 by bberger         ###   ########.fr       */
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
// prompt est une boucle infinie 
// use_signal pour savoir si ctl c ou ctl d sont appele
// get_line: promtpt traitement 
// line_is_not_empty est un strlen de la str
// execute_line lance parsing qui est en realite tokensisation

void	create_history(char *line)
{
	int	fd;

	add_history(line);
	fd = open("history.log", O_CREAT | O_WRONLY | O_APPEND, 0777);
	write_line(line, fd);
}
// add_history (part od readline library) allows the user to recall and reuse previous commands using the arrow keys or other Readline functionality.

void	write_line(char *line, int fd)
{
	ft_putstr_fd(line, fd);
	ft_putstr_fd("\n", fd);
}
// mise en place de la fonction ft_pustr_fd de la libft
