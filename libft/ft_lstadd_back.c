/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:31:29 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/31 12:13:41 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*position de lst renvoie lst*/
t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

/** 
 * Ajoute l’élément new à la fin de la liste.
 * (alst)L’adresse du pointeur vers le premier élément
 * de la liste.
 * (new)L’adresse du pointeur vers l’élément à rajouter
 * à la liste.
 **/
void	ft_lstadd_back(t_stack **alst, t_stack *new)
{
	t_stack	*n;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	n = ft_lstlast(*(alst));
	n->next = new;
}
