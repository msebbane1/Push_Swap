/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:17:20 by msebbane          #+#    #+#             */
/*   Updated: 2022/04/05 14:07:54 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/* PARSING */
/*
- [Arguments] que des chiffres/nb ou chiffres/nb negatifs √
- [Arguments] fonctionne avec "" √
- [Arguments] Retourne une erreur si ce ne sont pas des chiffres √
- [Arguments] Pas de caracteres doublons √
- [Arguments] Compris dans les int √
- Stocker lstnew(argv [1 NULL]) dans ma stack a √
- [Arguments] Si ils sont deja trie de rien afficher
*/
void	index_stack(t_stack **stack_a)
{
	int		i;
	t_stack	*tmp;
	t_stack	*tmp2;

	i = 0;
	tmp = *stack_a;
	tmp2 = *stack_a;
	while (tmp)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
	while (i <= len_stack(stack_a))
	{
		tmp = *stack_a;
		while (tmp)
		{
			if (tmp->valeur <= tmp2->valeur && tmp->index == 0)
				tmp2 = tmp;
			tmp = tmp->next;
		}
		tmp2->index = 1;
		tmp2->valeur = i;
		i++;
	}
}

int	check_double(t_stack *stack_a)
{
	t_stack	*tmp;

	while (stack_a)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (tmp->valeur == stack_a->valeur)
				return (1);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

void	free_split(char **copy_stock_a)
{
	char	**tmp;

	tmp = copy_stock_a;
	while (*tmp)
		free(*tmp++);
	free(copy_stock_a);
}

/* Fonction qui gere les " ", qui permet de stocker mes arguments dans 
la stack a et de transformer mes nb avec atoi */
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
			if (!(ft_isdigit(stock_a[y])))
				return (1);
			if ((ft_atoi(argv[i]) == 0 && argv[i][0] != '0') ||
				(ft_atoi(stock_a[y]) == 0 && stock_a[y][0] != '0'))
				return (1);
			y++;
		}
		i++;
		y = 0;
		free_split(stock_a);
	}
	return (0);
}

/* Fonction qui verifie si ma liste est deja trier */
int	check_sort(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->valeur < tmp->next->valeur)
			tmp = tmp->next;
		else if (tmp->valeur > tmp->next->valeur)
			return (0);
	}
	return (1);
}
