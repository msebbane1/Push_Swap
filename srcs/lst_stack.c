/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:11:24 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/31 12:12:00 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Nouvelle stack NULL (Le debut de ma stack) */
t_stack	*new_stack(void)
{
	return (NULL);
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

/* Boolean savoir si ma stack est NULL */
int	is_empty_stack(t_stack *list)
{
	if (list == NULL)
		return (1);
	return (0);
}

/* Afficher ma stack */
void	print_stack(t_stack *list)
{
	if (is_empty_stack(list))
	{
		ft_putstr_fd("Rien a afficher, la pile est vide", 1);
		return ;
	}
	while (!is_empty_stack(list))
	{
		printf("%d\n", list->valeur);
		list = list->next;
	}
}
