/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:00:50 by bberger          #+#    #+#             */
/*   Updated: 2023/05/31 13:35:39 by bberger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!(lst) || !(f))
		return ;
	while (lst)
	{
		(f)(lst->content);
		lst = lst->next;
	}
}

/* Le but de cette fonctions est d'appliquer a chaque liste de la liste
 * chainer la fonctions (f)
 *
 * on verifie si la liste et la fonction de sont pas vide
 * tant que lst n'est pas egale a NULL
 * on applique la fonction f aux contenue de la liste
 * on passe a la liste suivante
 */
