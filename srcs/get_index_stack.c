/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:43:24 by msebbane          #+#    #+#             */
/*   Updated: 2022/04/05 14:35:58 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Recupere l'index du haut, analyse la pile A à partir du haut pour confirmer 
si l'un des numéros du bloc 1 existe à l'intérieur. */
int	get_index_up(t_stack **stack_a, int limit)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->valeur <= limit)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

/* Recupere l'index du bas, analyse à nouveau la pile A à partir du bas et 
voit si un numéro est différent du bloc 1 existe dans cette liste.*/
int	get_index_down(t_stack **stack_a, int limit)
{
	int		i;
	int		down;
	t_stack	*tmp;

	i = 0;
	down = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->valeur <= limit)
			down = i;
		i++;
		tmp = tmp->next;
	}
	return (down);
}

/* Recupere le minimun dans la stack_a */
int	get_index_min(t_stack **stack_a)
{
	int		i;
	int		min;
	int		val;
	t_stack	*tmp;

	tmp = *stack_a;
	val = tmp->valeur;
	i = 0;
	min = i;
	while (tmp)
	{
		if (tmp->valeur < val)
		{
			val = tmp->valeur;
			min = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min);
}

int	get_index_max(t_stack **stack_b)
{
	int		i;
	int		max;
	int		val;
	t_stack	*tmp;

	tmp = *stack_b;
	val = tmp->valeur;
	i = 0;
	max = i;
	while (tmp)
	{
		if (tmp->valeur > val)
		{
			val = tmp->valeur;
			max = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max);
}

int	get_valeur_max(t_stack **stack_b)
{
	int		val;
	t_stack	*tmp;

	tmp = *stack_b;
	val = tmp->valeur;
	while (tmp)
	{
		if (tmp->valeur > val)
			val = tmp->valeur;
		tmp = tmp->next;
	}
	return (val);
}
