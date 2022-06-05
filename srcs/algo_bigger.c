/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:51:13 by jannabel          #+#    #+#             */
/*   Updated: 2022/02/26 12:51:19 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	first_sort(t_stk **a, t_stk **b, int len)
{
	int		i;
	int		pvt;
	t_stk	*tmp1;
	t_stk	*tmp2;

	i = len;
	while (i >= ft_abs(len / 4))
	{
		tmp1 = ft_lst_dup(*a);
		pvt = get_pivot(tmp1);
		while (check_pivot((*a), pvt, 1) && (*a))
		{
			if ((*a)->num <= pvt)
			{
				tmp2 = *a;
				pick_case(a, b, PB);
				i--;
				free(tmp2);
			}
			else
				normalize_a(a, b, pvt);
		}
		free_stk(&tmp1);
	}
}

void	second_sort(t_stk **a, t_stk **b, int len)
{
	int		min;
	t_stk	*tmp;

	tmp = NULL;
	while (*a && !check_sort(a, len))
	{
		min = get_min(*a);
		tmp = (*a)->nxt;
		while ((*a)->num != min && tmp && tmp->num == min)
			pick_case(a, b, SA);
		while (list_size(*a) && check_pivot((*a), min, 1))
		{
			if ((*a)->num == min)
			{
				tmp = *a;
				pick_case(a, b, PB);
				free(tmp);
				len--;
			}
			else
				normalize_a(a, b, min);
		}
	}
}

void	third_sort(t_stk **a, t_stk **b, int max)
{
	t_stk	*tmp;

	tmp = NULL;
	while (*b)
	{
		max = get_max(*b);
		while (check_pivot((*b), max, 2))
		{
			max = get_max(*b);
			tmp = (*b)->nxt;
			while ((*b)->num != max && tmp && tmp->num == max)
				pick_case(a, b, SB);
			while (((*b)->num != max) && *b)
				normalize_b(a, b, max);
			while (*b && (*b)->num == max)
			{
				tmp = *b;
				pick_case(a, b, PA);
				max = get_max(*b);
				free(tmp);
			}
		}
	}
}

void	sort_bigger(t_stk **a, t_stk **b, int len)
{
	int	max;

	max = 0;
	first_sort(a, b, len);
	second_sort(a, b, len);
	third_sort(a, b, max);
	free_stk(a);
	free_stk(b);
}
