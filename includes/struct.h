/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:02:19 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/17 16:15:06 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/* Definition d'une Pile */
typedef struct s_stack
{
	int				valeur;
	int				index;
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
void	sa(t_stack **stack_a, int print);
void	pa(t_stack **stack_a, t_stack **stack_b, int print);
void	rra(t_stack **stack_a, int print);
void	ft_lstadd_front(t_stack **alst, t_stack *new);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b, int print);
void	ra(t_stack **stack_a, int print);
void	sb(t_stack **stack_b, int print);
void	rb(t_stack **stack_b, int print);
void	rrb(t_stack **stack_b, int print);
int		len_stack(t_stack **stack_a);
void	sorted_for_2(t_stack **stack_a);
void	sorted_for_3(t_stack **stack_a);
void	sort_small_stack(t_stack **stack_a, t_stack **stack_b);
void	sort_big_stack(t_stack **stack_a);

#endif