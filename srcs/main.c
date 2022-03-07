/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:48:26 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/07 14:24:38 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*PARSING*/
/*
- [Arguments] que des chiffres/nb ou chiffres/nb negatifs
- [Arguments] fonctionne avec ""
- [Arguments] Retourne une erreur si ce sont des caracteres
- [Arguments] Si ils sont deja trie de rien afficher
*/
int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!(ft_isdigit(argv[i])))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		if (argc <= 2)
			return (0);
		else
		{
			ft_putstr_fd("yess", 2);
		}
	i++;
	}
}