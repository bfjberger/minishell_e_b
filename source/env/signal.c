/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:07:02 by bberger          #+#    #+#             */
/*   Updated: 2023/10/05 17:07:10 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	use_signal(void)
{
	signal(SIGQUIT, pass);
	signal(SIGINT, call_prompt);
}
// on fait ctl+ la fct pass. pass lance la fct rl_on_new_line de readline
// on fait ctl+c la fct call_prompt 


void	call_prompt(int key)
{
	(void)key;
	rl_replace_line("", 0);
	rl_on_new_line();
	write(1, "\n", 1);
	rl_redisplay();
	update_variable_status_process(g_env, 130);
}
// rl_replace_line remplace la ligne par une ligne vide
// rl_on_new_line : replace le cursor a une autre ligne
// rl_redisplay: display the modified line
// update_variable_status_process: 


void	pass(int key)
{
	(void)key;
	rl_on_new_line();
}
// rl_on_new_line : replace le cursor a une autre ligne

void	exit_prompt(int key)
{
	(void)key;
	ft_printf("Exit...\n");
	exit(0);
}

void	add_signal_env_var(t_env *env)
{
	t_var	*signal_var;
	char	*value;
	char	*name;

	name = malloc_strcpy("?");
	value = malloc_strcpy("0");
	signal_var = init_env_variable(name, value, VALUE);
	add_new_env_variable(env, signal_var);
}
