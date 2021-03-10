/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:58:06 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/10 19:47:57 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_algo(t_swap *a, t_swap *b)
{
	int is_push;

	is_push = 0;
	while (a->stack[a->len - 2] < a->stack[a->len - 1]
		|| a->stack[a->len - 2] > a->stack[a->len - 3])
	{
		if (a->stack[a->len - 1] > a->stack[a->len - 2])
		{
			sa(a, b);
		}
		if (a->len > 2 && a->stack[a->len - 2] > a->stack[a->len - 3])
		{
			pb(a, b);
			is_push += 1;
		}
		if (a->stack[a->len - 1] < a->stack[a->len - 2] && is_push > 0)
		{
			pa(a, b);
			is_push -= 1;
		}
	}
}

void	sort_three(t_swap *a, t_swap *b)
{
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
		sort_three_algo(a, b);
	a->part->len = a->len;
}
