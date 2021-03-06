/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:50:57 by jannabel          #+#    #+#             */
/*   Updated: 2022/02/26 12:51:03 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	normalize(t_stk **a, t_stk **b, int min)
{
	int	idx;
	int	num;

	idx = get_idx((*a), min, 1);
	num = (list_size((*a)) / 2);
	if (num > idx)
		pick_case(a, b, RA);
	else
		pick_case(a, b, RRA);
}

void	case_with_10(t_stk **a, t_stk **b, int len)
{
	int		i;
	int		min;
	t_stk	*tmp1;
	t_stk	*tmp2;

	i = len;
	while (i > 3)
	{
		min = get_min(*a);
		tmp1 = (*a)->nxt;
		if ((*a)->num != min && tmp1 && tmp1->num == min)
			pick_case(a, b, SA);
		while (min != (*a)->num)
			normalize(a, b, min);
		if (min == (*a)->num)
		{
			tmp2 = *a;
			pick_case(a, b, PB);
			free(tmp2);
			i--;
		}
	}
}

void	sort_3(t_stk **a, t_stk **b, int op)
{
	pick_case(a, b, SA);
	pick_case(a, b, op);
}

void	case_with_3(t_stk **a, t_stk **b, int len)
{
	t_stk	*tmp;
	int		min;

	tmp = ft_lst_bottom(*a);
	min = get_min(*a);
	while (check_sort(a, len) == 0)
	{
		if ((*a)->num < (*a)->nxt->num && tmp->num == min)
			pick_case(a, b, RRA);
		else if ((*a)->num > (*a)->nxt->num && tmp->num == min)
			sort_3(a, b, RRA);
		else if ((*a)->nxt->num == min)
		{
			if ((*a)->num < tmp->num)
				pick_case(a, b, SA);
			else if ((*a)->num > tmp->num)
				pick_case(a, b, RA);
		}
		else if ((*a)->num == min && (*a)->nxt->num > tmp->num)
			sort_3(a, b, RA);
	}
}

void	sort_short(t_stk **a, t_stk **b, int len)
{
	t_stk	*tmp;

	tmp = NULL;
	if (len == 2 && (*a)->num > (*a)->nxt->num)
		pick_case(a, b, SA);
	if (len <= 3)
		case_with_3(a, b, len);
	else if (len > 3)
	{
		case_with_10(a, b, len);
		case_with_3(a, b, 3);
		while ((*b))
		{
			tmp = *b;
			pick_case(a, b, PA);
			free(tmp);
		}
		free_stk(b);
	}
	free_stk(a);
}
