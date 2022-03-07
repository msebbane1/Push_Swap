/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:50:58 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/07 16:15:57 by msebbane         ###   ########.fr       */
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
# include "struct.h"

void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(char *str);
int		ft_atoi(const char *nptr);
void	ft_lstadd_back(t_stack **alst, t_stack *new);
t_stack	*ft_lstnew(int valeur);
char	**ft_split(char const *s, char c);
t_stack	*ft_lstlast(t_stack *lst);
#endif