/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:18:38 by bberger          #+#    #+#             */
/*   Updated: 2023/09/26 18:18:48 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	same_name(char *first, char *second)
{
	if (same_str(first, second, ft_strlen(second)))
	{
		return (1);
	}
	return (0);
}
