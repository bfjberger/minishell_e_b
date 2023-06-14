/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:34:53 by bberger          #+#    #+#             */
/*   Updated: 2023/10/02 18:35:34 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_line(t_env *env, char *line)
{
	parsing(env, line);
	check_error_parsing(env);
	if (doesnt_have_error_parsing(env))
	{
		processing_cmd(env);
		processing_redirection(env);
		if (doesnt_have_error_processing(env))
			execution(env);
	}
	reset_counter_error(env);
	remove_all_token(env);
}
// parsing est en fait tokenization


int	env_have_multi_line(t_env *env)
{
	t_line	*line;
	int		nbr;

	line = get_first_line(env);
	nbr = 1;
	while (line)
	{
		nbr++;
		line = line->next;
	}
	if (nbr > 1)
		return (1);
	return (0);
}

void	execute_multi_line(t_env *env, t_line *line)
{
	while (line)
	{
		execute_line(env, line->content);
		line = line->next;
	}
}

void	parse_line_with_semicolon(t_env *env, char *line)
{
	int		index;
	int		start;
	int		end;
	char	*sub_line;

	index = 0;
	start = index;
	while (line[index])
	{
		if (line[index] == ';' || is_finish(line[index + 1]))
		{
			if (is_finish(line[index + 1]))
				end = index;
			else
				end = index - 1;
			sub_line = malloc_substrcpy(line, start, end);
			add_line_to_env(env, sub_line);
			start = index + 1;
		}
		index++;
	}
}

char	*get_line(void)
{
	struct termios	saved;
	struct termios	attributes;
	char			*line;

	tcgetattr(STDIN_FILENO, &saved);
	tcgetattr(STDIN_FILENO, &attributes);
	attributes.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);
	line = readline("[Minishell]$ ");
	if (is_null(line))
		return (NULL);
	create_history(line);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &saved);
	return (line);
}
// tcgetattr takes comme args: the terminal fd (ici: STDIN_FILENO) et un pointer sur la structure termios (ici l adresse de saved)
// tcg... recupere les attributs du terminal et le store dans la struct
// attributes.c_lflag &= ~ECHOCTL  sert a disable le flag ECHOCTL
// tcsetattr : change the attributs d un terminal; TCSAFLUSH est un flag specifiant que tout chgt doit s effectuer apres que toutes
// les sorties aient ete ecrites
// readline librairie...
// create_history 





