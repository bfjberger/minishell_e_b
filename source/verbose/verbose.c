/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:50:04 by bberger          #+#    #+#             */
/*   Updated: 2023/05/31 14:59:28 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ask_verbose(t_env *env)
{
	char	answer;
// att. scanf n est pas autorise
// a utiliser pour la prepa du prog mais pas pour la correction
	ft_printf("Minishell mode verbose [Y/N] ?");
	scanf("%c", &answer);
	if (answer == 'Y' || answer == 'y')
	{
		ft_printf("--- Minishell mode verbose activate ---\n");
		env->verbose = 1;
	}
	else if (answer == 'N' || answer == 'n')
		env->verbose = 0;
}
