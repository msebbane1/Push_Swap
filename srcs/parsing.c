/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:17:20 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/31 15:50:18 by msebbane         ###   ########.fr       */
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
int	check_double(t_stack *stack_a)
{
	t_stack	*tmp;

	while (stack_a) //Parcours ma stack a jusqu'au dernier element [1245] [245] [45] [5]
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

void	free_split(char **copy_stock_a)
{
	char	**tmp;

	tmp = copy_stock_a;
	while (*tmp)
		free(*tmp++);
	free(copy_stock_a);
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
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(stock_a[y]))); // arguments stock dans la stack a
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

void	set_chunk_for_big_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	limit_save;
	int	nb_chunk;

	if (len_stack(stack_a) > 5 && len_stack(stack_a) <= 100)
		nb_chunk = 5;
	else if (len_stack(stack_a) >= 100 && len_stack(stack_a) <= 500)
		nb_chunk = 12;
	else
		nb_chunk = len_stack(stack_a) / 15;
	limit_save = len_stack(stack_a) / nb_chunk; // ex : 10 nb aleatoires / 5 = 2
	sort_big_stack_100(stack_a, stack_b, limit_save);
}

/*
void    all_chuncks(t_stack **stack_a, int nb_chunck)
{
    if (len_stack(stack_a) <= 19)
        nb_chunck = 1;
    else if (len_stack(stack_a) >= 20 && len_stack(stack_a) <= 39)
        nb_chunck = 2;
    else if (len_stack(stack_a) >= 40 && len_stack(stack_a) <= 59)
        nb_chunck = 3;
    else if (len_stack(stack_a) >= 60 && len_stack(stack_a) <= 79)
        nb_chunck = 4;
    else if (len_stack(stack_a) >= 80 && len_stack(stack_a) <= 99)
        nb_chunck = 5;
}*/