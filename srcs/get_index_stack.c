/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:43:24 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/31 15:21:56 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_index_up(t_stack **stack_a, int limit)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->valeur <= limit)
		{
			//printf("i = %d\n", i);
			return (i);
		}
		i++;
		tmp = tmp->next;
	}
	return (i);
}

/* Recupere */
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
		{
			//printf("i = %d\n", i);
			down = i;
		}
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
			min = i; // recuperer le i la position
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
			max = i; // recuperer le i la position
		}
		tmp = tmp->next;
		i++;
	}
	//printf("max = %d\n", max);
	return (max);
}
