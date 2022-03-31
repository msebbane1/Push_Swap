/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:50:58 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/31 14:43:09 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>

/* Definition de ma Pile */
typedef struct s_stack
{
	int				valeur;
	struct s_stack	*next;
}				t_stack;

/* Prototypes des fonctions */

t_stack	*new_stack(void);
int		is_empty_stack(t_stack *list);
t_stack	*clear_stack(t_stack *list);
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
int		get_index_min(t_stack **stack);
void	sort_big_stack_100(t_stack **stack_a, t_stack **stack_b, int limit);
void	chunk(t_stack **stack_a, int limit);
void	search_median(t_stack **stack_a, int index_min);
int		get_index_min(t_stack **stack_a);
int		get_index_down(t_stack **stack_a, int limit);
int		get_index_up(t_stack **stack_a, int limit);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(char *str);
int		ft_atoi(const char *nptr);
void	ft_lstadd_back(t_stack **alst, t_stack *new);
t_stack	*ft_lstnew(int valeur);
char	**ft_split(char const *s, char c);
t_stack	*ft_lstlast(t_stack *lst);
int		check_double(t_stack *stack_a);
int		check_argv(t_stack **stack_a, char **argv);
int		check_sort(t_stack **stack_a);
void	big_stack_chunk(t_stack **stack_a, t_stack **stack_b);
void	set_chunk_for_big_stack(t_stack **stack_a, t_stack **stack_b);
int		ft_check_order(t_stack *stack_a);
int		check_int(t_stack *stack_a);

#endif