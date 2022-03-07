/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:02:19 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/07 10:50:36 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/* Definition d'une Pile */
typedef struct s_stack
{
	int				valeur;
	struct s_stack	*next;
}				t_stack;

/* Prototypes des fonctions */

t_stack	*new_stack(void);
int		is_empty_stack(t_stack *list);
t_stack	*push_stack(t_stack *list, int x);
t_stack	*pop_stack(t_stack *list);
t_stack	*clear_stack(t_stack *list);
int		top_stack(t_stack *list);
void	print_stack(t_stack *list);
#endif