/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:01:17 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/29 12:53:17 by msebbane         ###   ########.fr       */
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
int get_index_min(t_stack **stack)
{
    int     i;
    int     save;
    int     val;
    t_stack *tmp;

    tmp = *stack;
    val = tmp->valeur;
    i = 0;
    save = i;
    while (tmp)
    {
        if (tmp->valeur < val)
        {
            val = tmp->valeur;
            save = i; // recuperer le i la position
        }
        tmp = tmp->next;
        i++;
    }
    return (save);
}
/*
size_chunk = 0;
    limit = (p->limit * nb_chunk);
    while (size_chunk < p->limit && p->size_a != 0)*/

void    hold_chunk(t_stack **stack_a, int limit, int nb_chunk)
{
    int chunk_size;
    int index_min;

    chunk_size = 0;
    limit = (limit * nb_chunk);
    while (len_stack(stack_a) != 0 && chunk_size < limit)
    {
        index_min = get_index_min(stack_a);
        search_median(stack_a, index_min);
        chunk_size++;
    }
}

/* Cette fonction permet de minimiser le nb de coup, si l'index du minimum est plus petit que 
la median utilise juste ra, sinon rra
*/
void    search_median(t_stack **stack_a, int index_min)
{
    int median;
    int size;

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

/*
void    count_chunks(t_stack **stack_a, int nb_chunk, int limit)
{
    if (len_stack(stack_a) <= 100)
        nb_chunk = 5;
    limit = len_stack(stack_a) / nb_chunk;
}*/

void    sort_big_stack_100(t_stack **stack_a, t_stack **stack_b, int limit)
{
    int nb_chunk;

    nb_chunk = 1;
    while (len_stack(stack_a) != 0)
    {
        hold_chunk(stack_a, limit, nb_chunk);
        pb(stack_a, stack_b, 2);
        nb_chunk++;
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


/*
void    all_chuncks(t_stack **stack_a, int nb_chunck)
{
    if (len_stack(stack_a) <= 19)
        nb_chunck = 1;
    else if (len_stack(stack_a) >= 20 && len_stack(stack_a) <= 39)
        nb_chunck = 2;
    else if (len_stack(stack_a) >= 40 && len_stack(stack_a) <= 59)
        nb_chunck = 3;
    else if (len_stack(stack_a) >= 60 && len_stack(stack_a) <= 79)
        nb_chunck = 4;
    else if (len_stack(stack_a) >= 80 && len_stack(stack_a) <= 99)
        nb_chunck = 5;
}*/
