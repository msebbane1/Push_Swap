/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_is_sorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:50:14 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/17 16:56:33 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	sorted_for_3(t_stack **stack_a)
{
	int	tab[3];

	tab[0] = (*stack_a)->valeur;
	tab[1] = (*stack_a)->next->valeur;
	tab[2] = (*stack_a)->next->next->valeur;
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] > tab[0]) // [5] > [4] < [8] >
		sa(stack_a, 2);
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] < tab[0]) // [4] > [2] < [3] <
		ra(stack_a, 2);
	else if (tab[0] > tab[1] && tab[1] > tab[2] && tab[2] < tab[0]) // [4] > [3] > [1] <
	{
		sa(stack_a, 2);
		rra(stack_a, 2);
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] < tab[0]) // [7] < [9] > [1] <
		rra(stack_a, 2);
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] > tab[0]) // [1] < [5] > [2] >
	{
		rra(stack_a, 2);
		sa(stack_a, 2);
	}
}

/*void	index_stack(t_stack **stack_a)
{
	int		i;
	t_stack	*tmp;
	t_stack *tmp2;

	i = 0;
	tmp = *stack_a;
	tmp2 = *stack_a;
	while (tmp)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
	while (i < len_stack(stack_a))
	{
		tmp = *stack_a;
		tmp2 = *stack_a;
		while (tmp)
		{
			if (tmp->valeur < tmp2->valeur && tmp->index == 0)
				tmp2 = tmp;
			tmp = tmp->next;
		}
		tmp2->index = i;
		i++;
	}
	print_stack(*stack_a);
}*/

int	get_index_min(t_stack **stack)
{
	int		i;
	int		save;
	int		val;
	t_stack	*tmp;

	tmp = *stack;
	val = tmp->valeur;
	i = 0;
	save = i;
	while (tmp)
	{
		if (tmp->valeur < val)
		{
			val = tmp->valeur;
			save = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (save);
}

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


// trouver les 2 plus petit les mettre dans ma stack b trier les 3 nombres puis repush mes 2 chiffre dans b dans a en haut de ma stack
/*
void	sort_small_stack(t_stack **stack_a)
{
	int		i;
	int		j;
	t_stack	*tmp;
	int		tmp2;
	int		tab[5];

	i = 0;
	tmp = *stack_a;
	tab[0] = (*stack_a)->valeur;
	tab[1] = (*stack_a)->next->valeur;
	tab[2] = (*stack_a)->next->next->valeur;
	tab[3] = (*stack_a)->next->next->next->valeur;
	tab[4] = (*stack_a)->next->next->next->next->valeur;
	//printf("%d\n", len_stack(stack_a));
	while (tmp)
	{
		j = 0;
		//printf("tab = %d\n", j);
		while (j < len_stack(stack_a) - i)
		{
			//printf("%d\n", tab[j]);
			if (tab[0] > tab[1] || tab[1] > tab[2] || tab[2] > tab[3] || tab[3] > tab[4])
			{
				tmp2 = tab[0];
				tab[0] = tab[0 + 1];
				tab[0 + 1] = tmp2;
				printf("%d")
			}
			j++;
		}
		i++;
		tmp = tmp->next;
	}
	print_stack(*stack_a);
	printf("hello j'ai 5 arguments(non trier)");
}*/

/*
void	sort_big_stack(t_stack **stack_a)
{
	printf("hello j'ai plus de 5 arguments(non trier)");
}
*/