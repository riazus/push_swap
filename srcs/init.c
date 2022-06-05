/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:52:05 by jannabel          #+#    #+#             */
/*   Updated: 2022/02/26 12:52:07 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_var	*ft_init_var(t_var *v)
{
	v = (t_var *)malloc(sizeof(t_var));
	if (v == NULL)
		exit(1);
	v->a = NULL;
	v->b = NULL;
	v->len = 0;
	v->line = NULL;
	v->split = NULL;
	return (v);
}
