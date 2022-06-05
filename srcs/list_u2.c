/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_u2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:53:09 by jannabel          #+#    #+#             */
/*   Updated: 2022/02/26 12:53:12 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stk	*ft_lst_dup(t_stk *stk)
{
	t_stk	*tmp1;
	t_stk	*tmp2;

	tmp1 = malloc(sizeof(t_stk));
	ft_bzero(tmp1, sizeof(t_stk));
	tmp2 = tmp1;
	while (stk)
	{
		tmp1->num = stk->num;
		if (stk->nxt)
		{
			tmp1->nxt = malloc(sizeof(t_stk));
			ft_bzero(tmp1->nxt, sizeof(t_stk));
			tmp1 = tmp1->nxt;
		}
		stk = stk->nxt;
	}
	tmp1 = tmp2;
	return (tmp1);
}

t_stk	*ft_lst_bottom(t_stk *a)
{
	t_stk	*tmp;

	tmp = a;
	while ((tmp)->nxt)
		(tmp) = (tmp)->nxt;
	return (tmp);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_arg(char **arg)
{
	if (*arg)
		free(*arg);
	*arg = NULL;
}
