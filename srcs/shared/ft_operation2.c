/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:32:14 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/10 19:42:05 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_swap *a, t_swap *b)
{
	int64_t	swp;
	int64_t	i;

	(void)b;
	if (a->len == 0)
		return ;
	i = a->len - 1;
	swp = a->stack[a->len - 1];
	while (i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[0] = swp;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_swap *a, t_swap *b)
{
	int64_t	swp;
	int64_t	i;

	(void)a;
	if (b->len == 0)
		return ;
	i = b->len - 1;
	swp = b->stack[b->len - 1];
	while (i > 0)
	{
		b->stack[i] = b->stack[i - 1];
		i--;
	}
	b->stack[0] = swp;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_swap *a, t_swap *b)
{
	int64_t	swp;
	int64_t	i;

	if (a->len > 0)
	{
		i = a->len;
		swp = a->stack[a->len - 1];
		while (--i > 0)
			a->stack[i] = a->stack[i - 1];
		a->stack[0] = swp;
	}
	if (b->len > 0)
	{
		i = b->len;
		swp = b->stack[b->len - 1];
		while (--i > 0)
			b->stack[i] = b->stack[i - 1];
		b->stack[0] = swp;
	}
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_swap *a, t_swap *b)
{
	int64_t	swp;
	size_t	i;

	(void)b;
	if (a->len == 0)
		return ;
	i = 0;
	swp = a->stack[0];
	while (i < a->len)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->stack[a->len - 1] = swp;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_swap *a, t_swap *b)
{
	int64_t	swp;
	size_t	i;

	(void)a;
	if (b->len == 0)
		return ;
	i = 0;
	swp = b->stack[0];
	while (i < b->len)
	{
		b->stack[i] = b->stack[i + 1];
		i++;
	}
	b->stack[b->len - 1] = swp;
	ft_putstr_fd("rrb\n", 1);
}
