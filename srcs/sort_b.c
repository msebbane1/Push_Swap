/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:48:37 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/17 17:02:21 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* sb (swap b) : échange les 2 premiers éléments en haut de la pile b.
Ne rien faire s'il n'y a qu'un ou aucun élément.*/
void	sb(t_stack **stack_b, int print)
{
	t_stack	*tmp;

	if (*stack_b == ft_lstlast(*stack_b))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	if (print)
		ft_putstr_fd("sb\n", 1);
}

/* pb (appuyez sur b) : Prenez le premier élément en haut de a et 
placez-le en haut de b. Ne rien faire si a est vide.*/
void	pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_b, tmp);
	if (print)
		ft_putstr_fd("pb\n", 1);
}

/* rb (rotation b) : décale vers le haut tous les éléments de la pile b de 1.
Le premier élément devient le dernier.*/
void	rb(t_stack **stack_b, int print)
{
	t_stack	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_b, tmp);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

/* rrb (rotation inverse b) : décale tous les éléments de la pile b de 1.
Le dernier élément devient le premier.*/
void	rrb(t_stack **stack_b, int print)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = *stack_b;
	while (tmp->next->next != NULL)
		tmp = tmp->next; // avant dernier element;
	last = ft_lstlast(*stack_b); // stock 6 dernier element
	tmp->next = NULL; // apres 6 = NULL
	ft_lstadd_front(stack_b, last);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}
