/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:48:26 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/31 15:16:18 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	(void) argc;
	stack_a = new_stack();
	stack_b = new_stack();
	if (check_argv(&stack_a, argv) || check_double(stack_a))
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	if (len_stack(&stack_a) == 1 || check_sort(&stack_a) == 1)
		return (1);
	if (len_stack(&stack_a) == 2)
		sa(&stack_a, 2);
	else if (len_stack(&stack_a) == 3)
		sorted_for_3(&stack_a);
	else if (len_stack(&stack_a) <= 5)
		sort_small_stack(&stack_a, &stack_b);
	else
		set_chunk_for_big_stack(&stack_a, &stack_b);
	return (0);
}

/* Test = ft_lstadd_back(&stack_b, ft_lstnew(7)); // arguments stock dans la stack b */
