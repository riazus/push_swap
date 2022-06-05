/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:53:59 by jannabel          #+#    #+#             */
/*   Updated: 2022/02/26 12:54:02 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	s_stk(t_stk **top)
{
	int		i;
	int		j;
	t_stk	*tmp;

	tmp = NULL;
	if ((*top) && (*top)->nxt)
	{
		tmp = *top;
		i = (*top)->num;
		j = (*top)->nxt->num;
		tmp = *top;
		(*top)->num = j;
		tmp = *top;
		(*top)->nxt->num = i;
		(*top) = tmp;
	}
}
