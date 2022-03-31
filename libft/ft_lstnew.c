/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:06:58 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/31 12:13:53 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** 
 * Alloue avec malloc et renvoie un nouvel élément. la variable valeur 
 * est initialisée à l’aide de la valeur du paramètre list. 
 * La variable ’next’ est initialisée à NULL.. 
 **/
t_stack	*ft_lstnew(int valeur)
{
	t_stack	*new_element;

	new_element = malloc(sizeof(t_stack));
	if (!new_element)
		return (NULL);
	new_element->valeur = valeur;
	new_element->next = NULL;
	return (new_element);
}
