/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:19:48 by bberger          #+#    #+#             */
/*   Updated: 2023/05/31 13:35:39 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		i;

	str = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
int main ()
{
	char s[] = "123456789";
	int c = '3';
	size_t n = 4;
	printf("%s\n",ft_memchr(s, c, n));
}
*/
