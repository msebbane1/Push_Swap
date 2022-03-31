/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:51:53 by msebbane          #+#    #+#             */
/*   Updated: 2022/03/30 11:56:01 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11
void	ft_move_one(int move, t_pile *p)
{
	if (move == 1)
	{
		ft_sa(p);
		ft_aff_move(SA);
	}
	else if (move == 2)
	{
		ft_sb(p);
		ft_aff_move(SB);
	}
	else if (move == 3)
	{
		ft_ss(p);
		ft_aff_move(SS);
	}
	else if (move == 4)
	{
		ft_pa(p);
		ft_aff_move(PA);
	}
}

void	ft_move_two(int move, t_pile *p)
{
	if (move == PB)
	{
		ft_pb(p);
		ft_aff_move(PB);
	}
	else if (move == RA)
	{
		ft_ra(p);
		ft_aff_move(RA);
	}
	else if (move == RB)
	{
		ft_rb(p);
		ft_aff_move(RB);
	}
	else if (move == RR)
	{
		ft_rr(p);
		ft_aff_move(RR);
	}
}

void	ft_move_three(int move, t_pile *p)
{
	if (move == RRA)
	{
		ft_rra(p);
		ft_aff_move(RRA);
	}
	else if (move == RRB)
	{
		ft_rrb(p);
		ft_aff_move(RRB);
	}
	else if (move == RRR)
	{
		ft_rrr(p);
		ft_aff_move(RRR);
	}
}

void	ft_use(int move, t_pile *p)
{
	if (move <= 4)
		ft_move_one(move, p);
	else if (move >= 5 && move < 9)
		ft_move_two(move, p);
	else
		ft_move_three(move, p);
}