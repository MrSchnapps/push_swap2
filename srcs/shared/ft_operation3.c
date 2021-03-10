/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:06:46 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/10 19:42:08 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_swap *a, t_swap *b)
{
	int64_t	swp;
	int		i;

	if (a->len > 0)
	{
		i = -1;
		swp = a->stack[0];
		while (++i < (int)a->len)
			a->stack[i] = a->stack[i + 1];
		a->stack[a->len - 1] = swp;
	}
	if (b->len > 0)
	{
		i = -1;
		swp = b->stack[0];
		while (++i < (int)b->len)
			b->stack[i] = b->stack[i + 1];
		b->stack[b->len - 1] = swp;
	}
	ft_putstr_fd("rrr\n", 1);
}
