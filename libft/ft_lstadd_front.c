/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:59:03 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/09 14:31:30 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/** 
 * Ajoute l’élément ’new’ au début de la liste.
 * (alst)L’adresse du pointeur vers le premier élément
 * de la liste.
 * (new)L’adresse du pointeur vers l’élément à rajouter
 * à la liste.
 **/
void	ft_lstadd_front(t_stack **alst, t_stack *new)
{
	new->next = *alst;
	*alst = new;
}
