/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:08:32 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/07 11:23:35 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*char	error_msg(char *msg)
{
	//ft_putstr_fd("Error :", 2);
	exit (0);
	return (0);
}*/

int	main(void)
{
	
	/*Creation d'une stack*/

	t_stack	*sa;

	sa = new_stack(); // La stack est a NULL
	if (is_empty_stack(sa))
		ft_putstr_fd("La Pile est vide.\n", 2);
	else
		ft_putstr_fd("La Pile a des elements.\n", 2);
	print_stack(sa);
	printf("---------------\n");



	
	/*Afficher le dernier element en haut de la list [enpiler]*/
	sa = push_stack(sa, 14);
	sa = push_stack(sa, 47);
	sa = push_stack(sa, 23);
	sa = push_stack(sa, 31);
	print_stack(sa);
	printf("---------------\n");
	/*Le dernier element ajoute est le premier enlever*/
	sa = pop_stack(sa);
	print_stack(sa);
	printf("---------------\n");
	/* Vider la pile */
	sa = clear_stack(sa);
	print_stack(sa);
}
