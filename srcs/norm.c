/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:53:33 by jannabel          #+#    #+#             */
/*   Updated: 2022/02/26 12:53:36 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	normalize_a(t_stk **a, t_stk **b, int pvt)
{
	int	idx;
	int	num;

	idx = get_idx((*a), pvt, 1);
	num = (list_size((*a)) / 2);
	if (idx < num)
		pick_case(a, b, RA);
	else
		pick_case(a, b, RRA);
}

void	normalize_b(t_stk **a, t_stk **b, int pvt)
{
	int	idx;
	int	num;

	idx = get_idx((*b), pvt, 2);
	num = ft_abs((list_size((*b)) / 2));
	if (idx < num && *b)
		pick_case(a, b, RB);
	else if (*b)
		pick_case(a, b, RRB);
}
