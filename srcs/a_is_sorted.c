/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_is_sorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:50:14 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/16 13:58:56 by msebbane         ###   ########.fr       */
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
	//printf("%d", i);
	return (i);
}

void	is_sorted_2(t_stack **stack_a)
{
	if (len_stack(stack_a) == 2)
	{
		sa(stack_a, 2);
	}
}

/*
void	is_sorted_3(t_stack **stack_a)
{
	
}*/