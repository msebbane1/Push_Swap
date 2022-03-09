/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:48:26 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/09 12:11:02 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*PARSING*/
/*
- [Arguments] que des chiffres/nb ou chiffres/nb negatifs √
- [Arguments] fonctionne avec "" √
- [Arguments] Retourne une erreur si ce ne sont pas des chiffres √
- [Arguments] Si ils sont deja trie de rien afficher
- [Arguments] Pas de caracteres doublons √
- [Arguments] Compris dans les int
- Stocker lstnew(argv [1 NULL]) dans ma stack a √
*/
/*void	check_int(t_stack *stack_a)
{
	if (ft_atoi(stock_a[y] < -2147483648 || ft_atoi(stock_a[y] > 2147483647)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
}*/
int	check_double(t_stack *stack_a)
{
	t_stack	*tmp;

	while (stack_a) // Parcours ma stack a jusqu'au dernier element [1245] [245] [45] [5]
	{
		tmp = stack_a->next; // [245] [45] [5] [NULL]
		while (tmp)
		{
			//printf("tmp = %d stack_a = %d\n", tmp->valeur, stack_a->valeur);
			if (tmp->valeur == stack_a->valeur)
				return (1);
			tmp = tmp->next;
		}
		stack_a = stack_a->next; // stack a = au dernier element [stack a vers le prochain element]
	}
	return (0);
}

int	check_argv(t_stack **stack_a, char **argv)
{
	int		i;
	int		y;
	char	**stock_a;

	i = 1;
	y = 0;
	while (argv[i])
	{
		stock_a = ft_split(argv[i], ' ');
		while (stock_a[y])
		{
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(stock_a[y])));
			if (!(ft_isdigit(stock_a[y])) || !(ft_isdigit(argv[i])))
				return (1);
			if (ft_atoi(argv[i]) == 0 || ft_atoi(stock_a[y]) == 0)
				return (1);
			y++;
		}
		i++;
		y = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	(void) argc;
	stack_a = new_stack();
	if (check_argv(&stack_a, argv) || check_double(stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
}
