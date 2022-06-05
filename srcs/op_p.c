/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:53:44 by jannabel          #+#    #+#             */
/*   Updated: 2022/02/26 12:53:47 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	p_stk(t_stk **a, t_stk **b, t_stk *tmp)
{
	tmp = NULL;
	if (*b == NULL && *a)
	{
		*b = (t_stk *)malloc(sizeof(t_stk));
		(*b)->prv = NULL;
		(*b)->num = (*a)->num;
		(*b)->nxt = NULL;
		(*a) = (*a)->nxt;
		(*a)->prv = NULL;
	}
	else
	{
		if (*a)
		{
			tmp = (t_stk *)malloc(sizeof(t_stk));
			tmp->num = (*a)->num;
			tmp->nxt = NULL;
			tmp->prv = NULL;
			add_front(b, tmp);
			(*a) = (*a)->nxt;
		}
	}
}
