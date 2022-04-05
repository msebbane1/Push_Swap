/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:50:14 by msebbane          #+#    #+#             */
/*   Updated: 2022/04/05 11:50:23 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Calcule toute ma stack */
int	len_stack(t_stack **stack_a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/* Fonction qui permet de trier les nb par 3 */
void	sorted_for_3(t_stack **stack_a)
{
	int	tab[3];

	tab[0] = (*stack_a)->valeur;
	tab[1] = (*stack_a)->next->valeur;
	tab[2] = (*stack_a)->next->next->valeur;
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] > tab[0])
		sa(stack_a, 2);
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] < tab[0])
		ra(stack_a, 2);
	else if (tab[0] > tab[1] && tab[1] > tab[2] && tab[2] < tab[0])
	{
		sa(stack_a, 2);
		rra(stack_a, 2);
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] < tab[0])
		rra(stack_a, 2);
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] > tab[0])
	{
		rra(stack_a, 2);
		sa(stack_a, 2);
	}
}

/* Trouver les 2 plus petit les mettre dans ma stack b trier les 3 nombres 
puis repush mes 2 chiffre dans b dans a en haut de ma stack */
void	sort_small_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	index;
	int	nb;

	if (len_stack(stack_a) == 5)
		nb = 2;
	else
		nb = 1;
	while (nb)
	{
		index = get_index_min(stack_a);
		while (index != 0)
		{
			ra(stack_a, 2);
			index--;
		}
		pb(stack_a, stack_b, 2);
		nb--;
	}
	sorted_for_3(stack_a);
	pa(stack_a, stack_b, 2);
	pa(stack_a, stack_b, 2);
}
