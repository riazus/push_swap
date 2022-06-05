/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:51:38 by jannabel          #+#    #+#             */
/*   Updated: 2022/02/26 12:51:43 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sort(t_stk **a, int len)
{
	t_stk	*tmp;

	if (list_size(*a) != len)
		return (0);
	(void)len;
	tmp = *a;
	while (tmp && tmp->nxt)
	{
		if ((tmp)->nxt != NULL && ((tmp)->num < (tmp)->nxt->num))
			(tmp) = tmp->nxt;
		else
			return (0);
	}
	return (1);
}

void	check_dup(char **av)
{
	int		i;
	int		j;
	char	*dup;

	i = 0;
	while (av[i])
	{
		dup = ft_strdup(av[i]);
		j = 0;
		while (av[j])
		{
			if (j == i)
				j++;
			else if (ft_strcmp(dup, av[j]) == 0)
			{
				ft_free_arg(&dup);
				ft_exit_ps("Error - duplicated values.\n", 1);
			}
			else
				j++;
		}
		ft_free_arg(&dup);
		i++;
	}
}

int	check_overflow(char *arg)
{
	long long	tmp;

	tmp = ft_atoi(arg);
	if (tmp >= -2147483647 && tmp <= 2147483647 && ft_strlen(arg) < 12)
		return (1);
	return (0);
}

int	check_numbers(char **av)
{
	int		i;
	int		j;

	i = -1;
	if (!av[0])
		ft_exit_ps("Error - no int found in args.\n", 1);
	while (av[++i])
	{
		j = -1;
		if (check_overflow(av[i]) == 0)
			ft_exit_ps("Error - Int Overflow.\n", 1);
		while (av[i][++j])
		{
			if (ft_isalpha(av[i][j]) == 1 || av[i][j] == '.'
			|| ((av[i][j]) == '-' && (av[i][j +1]) == '\0')
			|| ((av[i][j]) == '+' && (av[i][j +1]) == '\0'))
				ft_exit_ps("Error - Not valid input in arg.\n", 1);
		}
	}
	return (1);
}

int	check_pivot(t_stk *a, int pvt, int flag)
{
	while (a)
	{
		if (flag == 1)
		{
			if (a->num <= pvt)
				return (1);
			a = a->nxt;
		}
		if (flag == 2)
		{
			if (a->num == pvt)
				return (1);
			a = a->nxt;
		}
	}
	return (0);
}
