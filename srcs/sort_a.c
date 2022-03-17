/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:57:56 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/17 17:02:08 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* sa (swap a) : échange les 2 premiers éléments en haut de la pile a.
Ne rien faire s'il n'y a qu'un ou aucun élément.*/
void	sa(t_stack **stack_a, int print)
{
	t_stack	*tmp;

	if (*stack_a == ft_lstlast(*stack_a))
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	if (print)
		ft_putstr_fd("sa\n", 1);
}
/* pa (appuyez sur a) : prenez le premier élément en 
haut de b et placez-le en haut de a.
Ne rien faire si b est vide.*/

void	pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_a, tmp);
	if (print)
		ft_putstr_fd("pa\n", 1);
}

/* ra (faire pivoter a) : décaler vers le haut tous les 
éléments de la pile a de 1. Le premier élément devient le dernier.*/
void	ra(t_stack **stack_a, int print)
{
	t_stack	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_a, tmp);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

/* rra (rotation inverse a) : Décaler tous les éléments 
de la pile a de 1 vers le bas. Le dernier élément devient le premier.*/
void	rra(t_stack **stack_a, int print)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = *stack_a;
	while (tmp->next->next != NULL)
		tmp = tmp->next; // avant dernier;
	last = ft_lstlast(*stack_a); // stock 6 dernier element
	tmp->next = NULL; // apres 6 = NULL
	ft_lstadd_front(stack_a, last);
	if (print)
		ft_putstr_fd("rra\n", 1);
}
