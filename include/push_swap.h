/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:57:28 by jannabel          #+#    #+#             */
/*   Updated: 2022/02/26 13:00:46 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <ctype.h>
# include "../libft/libft.h"

# define PB 1
# define RA 2
# define RRA 3
# define PA 4
# define RB 5
# define RRB 6
# define SB 7
# define SA 8

typedef struct s_stk
{
	int				num;
	struct s_stk	*nxt;
	struct s_stk	*prv;
}	t_stk;

typedef struct s_var
{
	char			*line;
	char			**split;
	char			**av;
	int				ac;
	int				len;
	int				fd;
	t_stk			*a;
	t_stk			*b;
}	t_var;

void	rr_stk(t_stk **top, t_stk *tmp);
void	p_stk(t_stk **a, t_stk **b, t_stk *tmp);
void	r_stk(t_stk **top);
void	s_stk(t_stk **top);
int		check_sort(t_stk **a, int len);
void	check_dup(char **av);
int		check_numbers(char **av);
int		check_pivot(t_stk *a, int pvt, int flag);
void	pick_case(t_stk **a, t_stk **b, int len);
void	sort_short(t_stk **a, t_stk **b, int len);
void	sort_bigger(t_stk **a, t_stk **b, int len);
void	normalize_a(t_stk **a, t_stk **b, int pvt);
void	normalize_b(t_stk **a, t_stk **b, int pvt);
void	ft_exit_ps(char *arg, int err);
t_var	*ft_init_var(t_var *v);
t_stk	*fill_list(t_var *v, char **split, t_stk *tmp);
t_stk	*ft_lst_dup(t_stk *stk);
t_stk	*ft_lstsort(t_stk *stk);
int		list_size(t_stk *a);
void	add_back(t_stk **top, t_stk *new);
void	add_back_r(t_stk **top);
void	add_front(t_stk **top, t_stk *new);
void	free_stk(t_stk **stk);
t_stk	*ft_lst_bottom(t_stk *a);
int		ft_lstnbr(t_stk **stk, int idx);
void	ft_free_array(char **array);
void	ft_free_arg(char **arg);
int		get_min(t_stk *stk);
int		get_max(t_stk *stk);
int		get_idx(t_stk *stk, int num, int flag);
int		get_pivot(t_stk *stk);

#endif
