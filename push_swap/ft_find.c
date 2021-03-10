/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:55:15 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/10 01:06:57 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.hpp"
#include <time.h> //virer time

void	b_to_a(t_swap *a, t_swap *b)
{
	int i;
	int max;

	i = -1;
	if (b->len == 3)
		sort_three_b(a, b);
	if (b->part->len == 0)
		return ;
	else if (b->part->len == 1)
		while ((size_t)++i <= b->part->t_i[0])
			pa(a, b);
	else
	{
		max = (int)(b->part->t_i[b->part->len - 1] - b->part->t_i[b->part->len - 2]);
		while (++i < max)
			pa(a, b);
		if (max > 3)
			a->part->len = a->len - (max + 1);
	}
	b->part->len -= 1;
}

/*
** Calculate the median of A and push all the numbers <= median to B
*/

int		split_a(t_swap *a, t_swap *b)
{
	int64_t median;
	size_t	i;
	size_t	min;
	int		rot;

	rot = 0;
	min = a->part->len;
	if (getMedian(a->stack, min, a->len, &median))
		return (MERR);
	i = (int)(a->len - min);
	while (i > 0)
	{
		if (a->stack[a->len - 1] <= median)
			pb(a, b);
		else
		{
			ra(a, b);
			rot++;
		}
		i--;
	}
	if (b->len > 0)
		if (add_index(&b->part, b->len - 1))
			return (MERR);
	if (a->part->len != 0 && rot > 0)
		while (rot--)
			rra(a, b);
	return (0);
}

int		ft_find(t_swap *a, t_swap *b)
{
	while (!check_sorted(a))
	{
		while (a->len - a->part->len > 3)
			if (split_a(a, b))
				return (MERR);
		sort_three(a, b);
		b_to_a(a, b);
	}
	return (0);
}
