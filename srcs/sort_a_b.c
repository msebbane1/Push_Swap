/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:06:26 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/09 16:17:31 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* ss : sa et sb en même temps.*/
void	ss(t_stack *stack_a)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_putstr_fd("ss\n", 2);
}

/* rr : ra et rb en même temps.*/
void	rr(t_stack *stack_a)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_putstr_fd("rr\n", 2);
}

/* rrr : rra et rrb en même temps.*/
void	rrr(t_stack *stack_a)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_putstr_fd("rrr\n", 2);
}
