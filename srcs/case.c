/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:51:27 by jannabel          #+#    #+#             */
/*   Updated: 2022/02/26 12:51:29 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	next_next_case(t_stk **a, t_stk **b, int c)
{
	t_stk	*tmp;

	tmp = NULL;
	if (c == 7 && list_size(*b) > 1)
	{
		ft_putstr_fd("sb\n", 1);
		s_stk(b);
	}
	else if (c == 8 && list_size(*a) > 1)
	{
		ft_putstr_fd("sa\n", 1);
		s_stk(a);
	}
}

void	next_case(t_stk **a, t_stk **b, int c)
{
	t_stk	*tmp;

	tmp = NULL;
	if (c == 4)
	{
		ft_putstr_fd("pa\n", 1);
		p_stk(b, a, tmp);
		free(tmp);
	}
	else if (c == 5 && list_size(*b) > 1)
	{
		ft_putstr_fd("rb\n", 1);
		r_stk(b);
		free(tmp);
	}
	else if (c == 6 && list_size(*b) > 1)
	{
		ft_putstr_fd("rrb\n", 1);
		rr_stk(b, tmp);
		free(tmp);
	}
	else
		next_next_case(a, b, c);
}

void	pick_case(t_stk **a, t_stk **b, int c)
{
	t_stk		*tmp;

	tmp = NULL;
	if (c == 1)
	{
		ft_putstr_fd("pb\n", 1);
		p_stk(a, b, tmp);
		free(tmp);
	}
	else if (c == 2)
	{
		ft_putstr_fd("ra\n", 1);
		r_stk(a);
		free(tmp);
	}
	else if (c == 3 && list_size(*a) > 1)
	{
		ft_putstr_fd("rra\n", 1);
		rr_stk(a, tmp);
	}
	else
		next_case(a, b, c);
}
