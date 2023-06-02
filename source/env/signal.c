/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:07:02 by bberger          #+#    #+#             */
/*   Updated: 2023/06/05 17:07:10 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	use_signal(void)
{
	signal(SIGQUIT, pass);
	signal(SIGINT, call_prompt);
}
// signal de la library shell command tool signal.h see man signal. 
// SIGINT se lance qd on fait ctl C et SIGQUIT se lance pour terminer le process Ctl D

void	call_prompt(int key)
{
	(void)key;
	rl_replace_line("", 0);
	rl_on_new_line();
	write(1, "\n", 1);
	rl_redisplay();
	update_variable_status_process(g_env, 130);
}

void	pass(int key)
{
	(void)key;
	rl_on_new_line();
}

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
