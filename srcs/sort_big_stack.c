/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:01:17 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/29 16:31:31 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Etape 1 : trouver le plus petit et le mettre en haut de la stack a puis la pull dans la stack b
Etape 2 : Faire une fonction qui parcours ma stack a len / 2 pour la median en haut de ma median ra en bas = rra

Étape 1 : Analysez la pile A à partir du haut pour confirmer si l'un des numéros du bloc 1 existe à l'intérieur. Appelons ce numéro hold_first.
Étape 2 : Analysez à nouveau la pile A à partir du bas et voyez si un numéro différent du bloc 1 existe dans cette liste. 
J'appellerai ce numéro hold_second.
Étape 3 : Comparez le nombre de mouvements qu'il faudrait pour obtenir hold_first et hold_second au sommet.
*/
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
/* Chercher le minimun dans la stack_a */
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

void	hold_chunk(t_stack **stack_a, t_stack **stack_b, int limit_save, int nb_chunk)
{
	int	chunk_size;
	int	limit;
	int	index_up;
	int	index_down;

	chunk_size = 0;
	limit = (limit_save * nb_chunk); // ex = 10 nb aleatoire  -- limit = 2 * (1, 2,..,10) = 20
	//printf("limit = %d\n", limit);
	while (chunk_size < limit_save && len_stack(stack_a) != 0)
	{
		index_up = get_index_up(stack_a, limit);
		index_down = get_index_down(stack_a, limit);
		if ((len_stack(stack_a) + 1) - index_down < index_up)
			search_median(stack_a, index_down);
		else if ((len_stack(stack_a) + 1) - index_down > index_up)
			search_median(stack_a, index_up);
		else
			search_median(stack_a, index_up);
		pb(stack_a, stack_b, 2);
		//print_stack(*stack_a);
		//printf("up = %d, down = %d\n", chunk_up, chunk_down);
		chunk_size++;
	}
	//printf("chunk_size = %d\n", chunk_size);
}

/* Cette fonction permet de minimiser le nb de coup, si l'index du minimum est plus petit que 
la median utilise juste le coup ra, sinon rra
*/
void	search_median(t_stack **stack_a, int index_min)
{
	int	median;
	int	size;

	size = len_stack(stack_a);
	median = (size / 2);
	if (index_min < median)
	{
		while (index_min)
		{
			ra(stack_a, 2);
			index_min--;
		}
	}
	else if (index_min >= median)
	{
		while (index_min != size)
		{
			rra(stack_a, 2);
			index_min++;
		}
	}
}

void	sort_big_stack_100(t_stack **stack_a, t_stack **stack_b, int limit_save)
{
	int	nb_chunk;

	nb_chunk = 1;
	while (len_stack(stack_a) != 0)
	{
		hold_chunk(stack_a, stack_b, limit_save, nb_chunk);
		printf("nb_chunk = %d\n", nb_chunk);
		nb_chunk++; // 10 nb = 10 nb
	}
	while (len_stack(stack_b) != 0)
		pa(stack_a, stack_b, 2);
}
/*
void    sort_big_stack_100(t_stack **stack_a, t_stack **stack_b)
{
    int     index_min;

    while (len_stack(stack_a) != 0)
    {
        index_min = get_index_min(stack_a);
        search_median(stack_a, index_min);
        while (index != 0)
        {
            
            index--;
        }
        pb(stack_a, stack_b, 2);
    }
    while (len_stack(stack_b) != 0)
        pa(stack_a, stack_b, 2);
}*/