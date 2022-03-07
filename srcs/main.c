/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:48:26 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/07 16:28:32 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*PARSING*/
/*
- [Arguments] que des chiffres/nb ou chiffres/nb negatifs √
- [Arguments] fonctionne avec ""
- [Arguments] Retourne une erreur si ce ne sont pas des chiffres √
- [Arguments] Si ils sont deja trie de rien afficher
- [Arguments] Pas de caracteres doublons
- [Arguments] Compris dans les int
- back new atoi
*/
void	add(t_stack **stack_a, char **argv)
{
	int		i;
	int		y;
	char	**new_stack;

	i = 1;
	y = 0;
	while (argv[i])
	{
		//printf("argv = %s", argv[i]);
		new_stack = ft_split(argv[i], ' ');
		while (new_stack[y])
		{
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(new_stack[y])));
			y++;
		}
		i++;
		y = 0;
	}
	print_stack(*stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;

	(void) argc;
	i = 1;
	stack_a = new_stack();
	while (argv[i])
	{
		if (!(ft_isdigit(argv[i])))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		//if (argc <= 2)
			//return (0);
		else
		{
			//ft_putstr_fd("yess", 2);
			add(&stack_a, argv);
		}
	i++;
	}
}
