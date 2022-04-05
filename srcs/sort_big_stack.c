/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:01:17 by msebbane          #+#    #+#             */
/*   Updated: 2022/04/05 15:10:26 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
1. Trouver le plus petit nombre dans la pile A - Déplacez le plus petit nombre 
vers le haut de la pile A puis le poussez ce numéro vers la pile B.
4 .Répétez les étapes 1 à 3 jusqu'à ce que la pile A soit vide.
5 .Remettez tout dans la pile A une fois que la pile B contient tous les 
nombres, 
du plus grand au plus petit.

Etape 2 : Faire une fonction qui parcours ma stack a len / 2 pour la median en 
haut de 
ma median ra en bas = rra
Étape 3 : Analysez la pile A à partir du haut pour confirmer si l'un des 
numéros 
du bloc 1 existe à l'intérieur. Appelons ce numéro hold_first.
Étape 4 : Analysez à nouveau la pile A à partir du bas et voyez si un numéro 
différent du bloc 1 existe dans cette liste. 
J'appellerai ce numéro hold_second.
Étape 5 : Comparez le nombre de mouvements qu'il faudrait pour obtenir 
hold_first 
et hold_second au sommet.*/

/* Fonction qui trouve le plus grand nombre dans la pile B, 
et le déplace vers le haut et le pousse vers la pile A.
Recupere l'index max de len, si il est inferieur a la len / 2 
rotate sinon reverse
pa */
void	chunk_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	while (len_stack(stack_b) != 0)
	{
		while ((*stack_b)->valeur != get_valeur_max(stack_b))
		{
			if (get_index_max(stack_b) < len_stack(stack_b) / 2)
				rb(stack_b, 1);
			else
				rrb(stack_b, 1);
		}
		pa(stack_a, stack_b, 1);
	}
}

/* Cette fonction permet de minimiser le nb de coup, si l'index du minimum est 
plus petit que la median utilise juste le coup ra, sinon rra ca compare le 
nombre de mouvements qu'il faudrait pour obtenir 
index_up et index_down au sommet ex = Parce que 8 prend moins de coups, nous 
donnons la priorité à 8 et l'envoyons au sommet de la pile A.
*/
void	set_moves(t_stack **stack_a, int index)
{
	int	median;
	int	size;

	size = len_stack(stack_a);
	median = (size / 2);
	if (index < median)
	{
		while (index)
		{
			ra(stack_a, 2);
			index--;
		}
	}
	else if (index >= median)
	{
		while (index != size)
		{
			rra(stack_a, 2);
			index++;
		}
	}
}

/* Exemple = limit = 20 * 2 = 40 morceau (pour ne pas depasser la limit) - 
parcours jusqu'a 20
Dans ses 20 numero recupere l'index min du haut et du min bas --
Comparer le nombre de mouvements qu'il faudrait pour obtenir index_up
et index_down au sommet.
le nombre correct est maintenant en haut de la pile A. Mais 
avant de pousser le nombre vers la pile B. on vérifie si le nombre qu'on pousse
est soit plus grand ou plus petit que tous les autres nombres de la pile B. 
Puisque nous ne nous contentons pas de pousser le plus petit nombre un à la 
fois.
*/
void	sort_chunk(t_stack **stack_a, t_stack **stack_b, int limit_save, int nb)
{
	int	chunk_size;
	int	limit;
	int	index_up;
	int	index_down;

	chunk_size = 0;
	limit = (limit_save * nb);
	while (chunk_size < limit_save && len_stack(stack_a) != 0)
	{
		index_up = get_index_up(stack_a, limit);
		index_down = get_index_down(stack_a, limit);
		if ((len_stack(stack_a) + 1) - index_down < index_up)
			set_moves(stack_a, index_down);
		else if ((len_stack(stack_a) + 1) - index_down > index_up)
			set_moves(stack_a, index_up);
		else
			set_moves(stack_a, index_up);
		pb(stack_a, stack_b, 1);
		chunk_size++;
	}
}

/* Fonction qui tri dans chaque chunks, qui va push dans la pile B 
puis la pile A est vide, chunk_stack_b = trouve 
le plus grand nombre dans la 
pile B, et le déplace vers le haut et le pousse vers la pile A. */
void	sort_big_stack_100(t_stack **stack_a, t_stack **stack_b, int limit_save)
{
	int	nb_chunk;

	nb_chunk = 1;
	while (len_stack(stack_a) != 0)
	{
		sort_chunk(stack_a, stack_b, limit_save, nb_chunk);
		nb_chunk++;
	}
	chunk_stack_b(stack_a, stack_b);
}

/* Fonction qui initialise mes chunks exemple 100 / 5 = 20 morceaux 
ou 10 nb aleatoires / 5 = 2 */
void	set_chunk_for_big_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	limit_save;
	int	nb_chunk;

	if (len_stack(stack_a) > 5 && len_stack(stack_a) <= 100)
		nb_chunk = 5;
	else if (len_stack(stack_a) >= 100 && len_stack(stack_a) <= 500)
		nb_chunk = 12;
	else
		nb_chunk = len_stack(stack_a) / 15;
	limit_save = len_stack(stack_a) / nb_chunk;
	sort_big_stack_100(stack_a, stack_b, limit_save);
}
