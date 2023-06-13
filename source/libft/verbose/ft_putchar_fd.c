/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:49:56 by bberger          #+#    #+#             */
/*   Updated: 2023/10/02 19:10:15 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	count_putchar_fd(char c, int *count, int fd)
{
	write(fd, &c, 1);
	*count += 1;
}
/*
int main ()
{
	ft_putchar_fd('c',1);
}
*/
