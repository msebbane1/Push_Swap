/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:48:26 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/29 15:07:48 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*PARSING*/
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
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(stock_a[y]))); // arguments stock dans la stack a
			if (!(ft_isdigit(stock_a[y])) || !(ft_isdigit(argv[i])))
				return (1);
			if ((ft_atoi(argv[i]) == 0 && argv[i][0] != '0') ||
				(ft_atoi(stock_a[y]) == 0 && stock_a[y][0] != '0'))
				return (1);
			y++;
		}
		i++;
		y = 0;
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
void	big_stack_chunk(t_stack **stack_a, t_stack **stack_b)
{
	int	limit_save;
	int	nb_chunk;

	if (len_stack(stack_a) > 5 && len_stack(stack_a) <= 100)
		nb_chunk = 5;
	else if (len_stack(stack_a) >= 100 && len_stack(stack_a) <= 500)
		nb_chunk = 11;
	else
		nb_chunk = len_stack(stack_a) / 15;
	limit_save = len_stack(stack_a) / nb_chunk; // ex : 10 nb aleatoires / 5 = 2
	sort_big_stack_100(stack_a, stack_b, limit_save);
}

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
		big_stack_chunk(&stack_a, &stack_b);
    //print_stack(stack_a);
	return (0);
}
//index_stack(&stack_a);
    //else if (len_stack(&stack_a) > 5)
        //sort_big_stack(&stack_a);
    
    //ft_lstadd_back(&stack_b, ft_lstnew(7)); // arguments stock dans la stack b
