/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:52:15 by jannabel          #+#    #+#             */
/*   Updated: 2022/02/26 12:52:19 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stk	*fill_list(t_var *v, char **split, t_stk *tmp)
{
	int		i;

	i = -1;
	while (split[++i])
	{
		tmp = malloc(sizeof(t_stk));
		if (tmp == NULL)
			return (NULL);
		tmp->num = ft_atoi(split[i]);
		if (tmp->num > 2147483647 || tmp->num < -2147483648)
			ft_exit_ps("ERROR - int overflow.\n", 1);
		tmp->nxt = NULL;
		tmp->prv = NULL;
		add_back(&v->a, tmp);
		tmp = NULL;
	}
	return (v->a);
}
