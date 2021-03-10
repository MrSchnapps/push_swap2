/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_size2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:15:59 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/10 19:49:23 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_min(int64_t nb, t_swap *s)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 1;
	while (i < s->len)
	{
		if (nb > s->stack[i])
			ret = 0;
		i++;
	}
	return (ret);
}

size_t	find_max(t_swap *s)
{
	int64_t test;
	size_t	i;
	size_t	ret;

	test = s->stack[0];
	i = 0;
	ret = 0;
	while (i < s->len)
	{
		if (test < s->stack[i])
		{
			test = s->stack[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

size_t	find_min(int64_t nb, t_swap *s)
{
	int64_t test;
	size_t	i;
	size_t	ret;

	test = INT32_MIN;
	i = 0;
	ret = s->len - 1;
	while (i < s->len)
	{
		if (s->stack[i] < nb && s->stack[i] > test)
		{
			test = s->stack[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

void	recover_a(t_swap *a, t_swap *b)
{
	size_t rot;

	rot = find_max(b);
	if (rot < b->len / 2)
	{
		rot++;
		while (rot-- > 0)
			rrb(a, b);
	}
	else
		while (rot++ < b->len - 1)
			rb(a, b);
	pa(a, b);
}

void	pusher_b(t_swap *a, t_swap *b)
{
	size_t rot;

	if (a->len > 0 && b->len > 0)
	{
		if (is_min(a->stack[a->len - 1], b))
			rot = find_max(b);
		else
			rot = find_min(a->stack[a->len - 1], b);
		if (rot < b->len / 2)
		{
			rot++;
			while (rot-- > 0)
				rrb(a, b);
		}
		else
			while (rot++ < b->len - 1)
				rb(a, b);
	}
	pb(a, b);
}
