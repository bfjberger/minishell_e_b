/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:02:08 by bberger          #+#    #+#             */
/*   Updated: 2023/05/31 15:04:56 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*g_env;

int	main(int argc, char **argv, char **env_var)
{
	t_env	*env;
	char	**env_variable;

	(void)argc;
	(void)argv;
	env_variable = malloc_strcpy_array(env_var);
	//alloc d un espace memoire pour y mettre le tab de str de env (prinenv)
	env = init_env(env_variable);
	// initatialisation de la structure env + mise en liste chainee du contenu du tab de env + ajout d'un ligne pou incorporer la variable error
	// ask_verbose(env);
	// mise en place du suivi du contenu a ne pas laisser pour la correction
	prompt(env);
	// minishell commence avec le traitement des args dans le prompt
	remove_all(env);
}
