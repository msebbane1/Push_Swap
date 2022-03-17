/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:46:00 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/17 16:34:38 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Nouvelle stack NULL (Le debut de ma stack) */
t_stack	*new_stack(void)
{
	return (NULL);
}
/********************************/

/* Boolean savoir si ma stack est NULL */
int	is_empty_stack(t_stack *list)
{
	if (list == NULL)
		return (1);
	return (0);
}
/*******************************/

/* Creation de l'element avec malloc*/
t_stack	*push_stack(t_stack *list, int x)
{
	t_stack	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->valeur = x;
	element->next = list;
	return (element);
}

/* Free stack */
t_stack	*clear_stack(t_stack *list)
{
	t_stack	*element;

	if (is_empty_stack(list))
		return (new_stack());
	element = list->next;
	free(list);
	return (clear_stack(element));
}

/* Afficher ma stack */
void	print_stack(t_stack *list)
{
	if (is_empty_stack(list))
	{
		ft_putstr_fd("Rien a afficher, la pile est vide", 2);
		return ;
	}
	while (!is_empty_stack(list))
	{
		printf("%d\n", list->valeur);
		list = list->next;
	}
}

t_stack	*pop_stack(t_stack *list)
{
	t_stack	*element;

	if (is_empty_stack(list))
		return (new_stack());
	element = list->next; // Toute la pile sauf le premier
	free(list);
	return (element);
}

/* Sommet de la pile retourne la valeur du sommet sauf si c'est NULL*/
int	top_stack(t_stack *list)
{
	if (is_empty_stack(list))
		return (0);
	return (list->valeur);
}