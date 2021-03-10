/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:58:06 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/09 14:59:56 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.hpp"

void	sort_three(t_swap *a, t_swap *b)
{
	//printf("\nOn Sort three\n");
	int is_push;

	is_push = 0;
	if (a->len <= 1)
		return ;
	else if (a->len - a->part->len == 2)
	{
		if (a->stack[a->len - 1] > a->stack[a->len - 2])
			sa(a, b);
	}
	else if (a->len == 3)
		sort_three_a(a, b);
	else
	{
		while (a->stack[a->len - 2] < a->stack[a->len - 1] || a->stack[a->len - 2] > a->stack[a->len - 3])
		{
			if (a->stack[a->len - 1] > a->stack[a->len - 2])
			{
				sa(a, b);
			}
			if (a->len > 2 && a->stack[a->len - 2] > a->stack[a ->len - 3])
			{
				pb(a, b);
				is_push += 1;
			}
			if (a->stack[a->len - 1] < a->stack[a ->len - 2] && is_push > 0)
			{
				pa(a, b);
				is_push -= 1;
			}
		}
	}
	a->part->len = a->len;
}

int		check_sorted_a(t_swap *s)
{
	size_t i;

	i = s->len - 1;
	while (i > 0)
	{
		if (s->stack[i] > s->stack[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void	sort_three_a(t_swap *a, t_swap *b)
{
	if (a->stack[a->len - 2] > a->stack[a->len - 1] && a->stack[a->len - 2] > a->stack[a->len - 3])
		rra(a, b);
	else if (a->stack[a->len - 1] > a->stack[a->len - 2] && a->stack[a->len - 1] > a->stack[a->len - 3])
		ra(a, b);
	if (!check_sorted_a(a))
		sa(a, b);
}

int		check_sorted_rev(t_swap *s)
{
	size_t i;

	i = s->len - 1;
	while (i > 0)
	{
		if (s->stack[i] < s->stack[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void	sort_three_b(t_swap *a, t_swap *b)
{
	if (b->stack[b->len - 1] < b->stack[b->len - 2] && b->stack[b->len - 1] < b->stack[b->len - 3])
		rb(a, b);
	else if (b->stack[b->len - 2] < b->stack[b->len - 1] && b->stack[b->len - 2] < b->stack[b->len - 3])
		rrb(a, b);
	if (!check_sorted_rev(b))
		sb(a, b);
}
