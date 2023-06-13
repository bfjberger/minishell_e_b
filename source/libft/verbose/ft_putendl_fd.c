/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:03:44 by bberger          #+#    #+#             */
/*   Updated: 2023/05/31 13:35:39 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!(s))
		return ;
	ft_putstr_fd (s, fd);
	write (fd, "\n", 1);
}
/*
int main ()
{
	char *s = "efefefewc";
	int fd = 1;
	ft_putendl_fd(s,fd);
	ft_putendl_fd(s,fd);
	ft_putendl_fd(s,fd);
}
*/
