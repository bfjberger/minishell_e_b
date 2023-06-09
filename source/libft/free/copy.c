/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:47:05 by bberger          #+#    #+#             */
/*   Updated: 2023/09/28 08:40:10 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*malloc_strcpy(char *origin)
{
	size_t	i;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(origin) + 1));
	i = 0;
	while (origin[i])
	{
		str[i] = origin[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*malloc_strcpy_index(char *origin, int len)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * len + 1);
	i = 0;
	while (origin[i] && i < len)
	{
		str[i] = origin[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*malloc_strcpy_after_index(char *origin, int index)
{
	int		len;
	int		range;
	char	*new;
	int		i;

	len = ft_strlen(origin);
	range = len - index;
	i = 0;
	new = malloc(sizeof(char) * range + 1);
	while (i < range)
	{
		new[i] = origin[index + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*malloc_substrcpy(char *origin, int start, int end)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	len = (end - start) + 1;
	new = malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		new[i] = origin[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
